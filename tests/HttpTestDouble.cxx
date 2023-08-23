#include <gmock/gmock.h>

#include <Http.h>

class HttpStub: public Http {
public:
    std::string returnResponse;
    std::string expectedUrl;

    void initialize() override {}
    std::string get(const std::string& url) const override { 
        verify(url);
        return returnResponse;
    }
    void verify(const std::string& url) const {
        ASSERT_THAT(url, testing::Eq(expectedUrl));
    }
};

TEST(PlaceDescriptionService, Returns_valid_json) {
    std::string urlStart = "https://someserver.com/api/test_json";

    HttpStub httpStub;
    httpStub.returnResponse = R"({"road": "123 Fake St})";
    httpStub.expectedUrl = urlStart;

    PlaceDescriptionService service{ &httpStub };

    auto description = service.description();
    ASSERT_EQ(description, "123 Fake St");
}