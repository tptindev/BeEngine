#ifndef CPOOLSIGNALS_H
#define CPOOLSIGNALS_H

#include <stdint.h>
#include <queue>
#include <unordered_map>
#include <functional>
#include <future>
#include <type_traits>
#include <memory>

class CPoolSignals
{
private:
    static CPoolSignals* s_instance;
    CPoolSignals();
    ~CPoolSignals();

    std::queue<uint8_t> m_ids;
    std::unordered_map<uint8_t, void(*)> m_pool;

public:
    CPoolSignals(const CPoolSignals& other) = delete;
    void operator=(const CPoolSignals& other) = delete;

    static CPoolSignals* instance();

    template<typename Fn, typename ...Args>
    void registerNotify(Fn& func, Args&&...args)
    {
        typedef std::result_of<decltype(func)&(Args)...> ret;

//        std::function<ret(decltype(args)...)> f = std::bind(func, std::forward<Args>(args)...);
//        std::packaged_task<ret(decltype(args)...)> package(f);
//        std::unique_ptr<decltype(package)> task = std::make_shared<decltype(package)>(f);
//        std::future<ret> promise = task.get_future();
    }

};

#endif // CPOOLSIGNALS_H
