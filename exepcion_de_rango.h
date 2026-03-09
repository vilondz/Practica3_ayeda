#include <exception>
#include <string>

class SlidingVectorException : public std::exception {
private:
    std::string mensaje_;
    std::string tipo_;
    bool delante_;
public:
    SlidingVectorException(const std::string& tipo,
                           int indice,
                           int inicio,
                           int fin)
    {
        mensaje_ = "Error en SlidingVector<" + tipo + "> : indice " +
                   std::to_string(indice) +
                   " fuera de rango [" +
                   std::to_string(inicio) + "," +
                   std::to_string(fin) + "]";
        tipo_ = tipo;
        if(indice > 0){
          delante_ = true;
        }
    }

    const char* what() const noexcept {
        return mensaje_.c_str();
    }
    const char* tipo() const noexcept {
        return tipo_.c_str();
    }
    const bool por_delante() const noexcept{
        return delante_;
    }
};