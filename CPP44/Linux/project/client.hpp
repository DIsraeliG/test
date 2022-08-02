class Json4String
{
public:
    Json4String(object jsonData) {
        val = jsonData;
    }

    ~Json4String() { cout << "~Json4String()" << endl; }

    std::string jsonToString()
    {
        cout << serialize(val) << endl;
    }

    object stringToJson()
    {
        cout << parse(val_to_server) << endl;
    }

private:
    object val;
    std::string val_to_server;
};