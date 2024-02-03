#include "CTilemapParser.h"
#include <Utils.h>
#include <LoggerDefines.h>

CTilemapParser::CTilemapParser()
{

}

CTilemapParser::~CTilemapParser()
{
    safeRelease(m_map.objectgroups->object);
    safeRelease(m_map.objectgroups);
    safeRelease(m_map.tilesets->image);
    safeRelease(m_map.tilesets->tiles);
    safeRelease(m_map.tilesets);
    safeRelease(m_map.layers->data);
    safeRelease(m_map.layers);
    _DEBUG("Release Instance CTilemapParser At address [%p]", this);
}

void CTilemapParser::loadFile(const char *file)
{
    m_xmlparser.loadFile(file);

    m_map.orientation       = m_xmlparser.rootAttribute("orientation");
    m_map.render_order      = m_xmlparser.rootAttribute("renderorder");
    m_map.width             = std::stoi(m_xmlparser.rootAttribute("width"));
    m_map.height            = std::stoi(m_xmlparser.rootAttribute("height"));
    m_map.tile_width        = std::stoi(m_xmlparser.rootAttribute("tilewidth"));
    m_map.tile_height       = std::stoi(m_xmlparser.rootAttribute("tileheight"));
    m_map.next_layer_id     = std::stoi(m_xmlparser.rootAttribute("nextlayerid"));
    m_map.next_object_id    = std::stoi(m_xmlparser.rootAttribute("nextobjectid"));
    m_map.tilesets          = new TmxTileSet[m_xmlparser.count("tileset")];
    m_map.layers            = new TmxLayer[m_xmlparser.count("layer")];
    m_map.objectgroups      = new TmxObjectGroup[m_xmlparser.count("objectgroup")];
}

int CTilemapParser::countWith(const char *tag)
{
    return m_xmlparser.count(tag);
}

TmxMap &CTilemapParser::map()
{
    return m_map;
}

void CTilemapParser::parse(int index, TmxTileSet &tileset)
{
    const char* tag = "tileset";
    tileset.name            = m_xmlparser.parseTagWith(index, tag, "name");
    tileset.first_global_id = std::stoi(m_xmlparser.parseTagWith(index, tag, "firstgid"));
    tileset.tile_count      = std::stoi(m_xmlparser.parseTagWith(index, tag, "tilecount"));
    tileset.columns         = std::stoi(m_xmlparser.parseTagWith(index, tag, "columns"));
    tileset.rows            = tileset.tile_count / tileset.columns;
    tileset.tile_width      = std::stoi(m_xmlparser.parseTagWith(index, tag, "tilewidth"));
    tileset.tile_height     = std::stoi(m_xmlparser.parseTagWith(index, tag, "tileheight"));

    {
        tileset.tiles           = new TmxTile[tileset.tile_count];
        printf("%s\n", tileset.name);
        for(int r = 0; r < tileset.rows; r++)
        {
            for(int c = 0; c < tileset.columns; c++)
            {
                int index = (r * tileset.columns) + c;
                tileset.tiles[index].id = tileset.first_global_id + index;
                printf("%d ", tileset.tiles[index].id);
            }
            printf("\n");
        }
        printf("\n");
    }

    {
        const char* tag = "tileset.image";
        tileset.image           = new TmxImage;
        tileset.image->source   = m_xmlparser.parseTagWith(index, tag, "source");
        tileset.image->width    = std::stoi(m_xmlparser.parseTagWith(index, tag, "width"));
        tileset.image->height   = std::stoi(m_xmlparser.parseTagWith(index, tag, "height"));
    }

    *(m_map.tilesets + index)   = std::move(tileset);
}

void CTilemapParser::parse(int index, TmxLayer &layer)
{
    const char* tag = "layer";
    layer.name              = m_xmlparser.parseTagWith(index, tag, "name");
    layer.x                 = std::stoi(m_xmlparser.parseTagWith(index, tag, "x"));
    layer.y                 = std::stoi(m_xmlparser.parseTagWith(index, tag, "y"));
    layer.width             = std::stoi(m_xmlparser.parseTagWith(index, tag, "width"));
    layer.height            = std::stoi(m_xmlparser.parseTagWith(index, tag, "height"));
    layer.visible           = static_cast<bool>(m_xmlparser.parseTagWith(index, tag, "visible"));

    {
        const char* tag = "layer.data";
        layer.data              = new TmxData;
        layer.data->encoding    = m_xmlparser.parseTagWith(index, tag, "encoding");
        layer.data->content     = m_xmlparser.tagContentWith(index, tag);
    }

    *(m_map.layers + index) = std::move(layer);
}

void CTilemapParser::parse(int index, TmxObjectGroup &objectgroup)
{
    const char* tag = "objectgroup";
    objectgroup.name             =  m_xmlparser.parseTagWith(index, tag, "name");
    objectgroup.id               = std::stoi(m_xmlparser.parseTagWith(index, tag, "id"));
    objectgroup.x                = std::stoi(m_xmlparser.parseTagWith(index, tag, "x"));
    objectgroup.y                = std::stoi(m_xmlparser.parseTagWith(index, tag, "y"));
    objectgroup.width            = std::stoi(m_xmlparser.parseTagWith(index, tag, "width"));
    objectgroup.height           = std::stoi(m_xmlparser.parseTagWith(index, tag, "height"));
    objectgroup.object           = new TmxObject[m_xmlparser.count("objectgroup.object")];
}

void CTilemapParser::parse(int index, TmxObject &object)
{
    const char* tag = "objectgroup.object";
    object.id               = std::stoi(m_xmlparser.parseTagWith(index, tag, "id"));
    object.x                = std::stoi(m_xmlparser.parseTagWith(index, tag, "x"));
    object.y                = std::stoi(m_xmlparser.parseTagWith(index, tag, "y"));
    object.width            = std::stoi(m_xmlparser.parseTagWith(index, tag, "width"));
    object.height           = std::stoi(m_xmlparser.parseTagWith(index, tag, "height"));
    //    object.shape            = m_xmlparser.parseTagWith(0, "objectgroup.object.")
}

void CTilemapParser::parse(int index, TmxRectangle &shape)
{
}

void CTilemapParser::parse(int index, TmxPoint &shape)
{
    const char* tag = "objectgroup.object.point";
    shape.id               = std::stoi(m_xmlparser.parseTagWith(index, tag, "id"));
    shape.x                = std::stoi(m_xmlparser.parseTagWith(index, tag, "x"));
    shape.y                = std::stoi(m_xmlparser.parseTagWith(index, tag, "y"));
}

void CTilemapParser::parse(int index, TmxEllipse &shape)
{
    const char* tag = "objectgroup.object.ellipse";
    shape.id               = std::stoi(m_xmlparser.parseTagWith(index, tag, "id"));
    shape.x                = std::stoi(m_xmlparser.parseTagWith(index, tag, "x"));
    shape.y                = std::stoi(m_xmlparser.parseTagWith(index, tag, "y"));
    shape.width            = std::stoi(m_xmlparser.parseTagWith(index, tag, "width"));
    shape.height           = std::stoi(m_xmlparser.parseTagWith(index, tag, "height"));
}

void CTilemapParser::parse(int index, TmxPolygon &shape)
{
    const char* tag = "objectgroup.object.polygon";
    shape.id               = std::stoi(m_xmlparser.parseTagWith(index, tag, "id"));
    shape.x                = std::stoi(m_xmlparser.parseTagWith(index, tag, "x"));
    shape.y                = std::stoi(m_xmlparser.parseTagWith(index, tag, "y"));

    const char* points     = m_xmlparser.parseTagWith(index, tag, "points");
    std::string points_str(points);
    std::string line;
    std::istringstream ss(points_str);
    while(std::getline(ss, line, ' '))
    {
        float x,y;
        std::istringstream line_ss(line);
        std::string point_str;
        std::getline(ss, point_str, ',');
        line_ss >> x >> y;
    }
}

