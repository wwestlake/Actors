#include <caf/all.hpp>
#include <iostream>
#include <cassert>
#include <string>

using std::endl;
using namespace caf;

namespace {

struct id { uint32_t value; };

template <class Inspector>
bool inspect(Inspector& f, id& x) {
    return f.apply(x.value);
}

struct user_record {
    id user_id;
    std::string user_name;
    std::string email;
    std::string display_name;
};

template <class Inspector>
bool inspect(Inspector& f, user_record& x) {
    return f.object(x).fields(f.field("user_id", x.user_id),
                              f.field("user_name", x.user_name),
                              f.field("email", x.email),
                              f.field("display_name", x.display_name));
}







void caf_main(actor_system& system) {
    

}

} // namespace

CAF_MAIN()
