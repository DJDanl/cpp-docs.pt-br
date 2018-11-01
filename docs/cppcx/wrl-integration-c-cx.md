---
title: Integração WRL (C++/CX)
ms.date: 01/22/2017
ms.assetid: 3ad43894-c574-477c-ad3e-240301f381d4
ms.openlocfilehash: a3c8b824d2cd932a7d284804f3f28781654045e0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50612115"
---
# <a name="wrl-integration-ccx"></a>Integração WRL (C++/CX)

Você pode combinar livremente o código de WRL com código de biblioteca de modelos em C++ Windows Runtime (WRL). Na mesma unidade de tradução, você pode usar objetos declarados com WRL handle-to-object (`^`) notação e WRL inteligentes ponteiro (`ComPtr<T>`) notação. No entanto, você deve tratar manualmente os valores de retorno e códigos de erro HRESULT da WRL e exceções do WRL.

## <a name="wrl-development"></a>Desenvolvimento de WRL

Para obter mais informações sobre criação e consumo de componentes da WRL, consulte [biblioteca de modelos em C++ Windows Runtime (WRL)](../windows/windows-runtime-cpp-template-library-wrl.md).

### <a name="example"></a>Exemplo

O trecho de código a seguir demonstra como usar a WRL e WRL para consumir classes de tempo de execução do Windows e examinar um arquivo de metadados.

O exemplo é tirado de um trecho de código no Fórum de aplicativos da Microsoft Store de construção. O autor desse snippet de código oferece os seguintes avisos de isenção de responsabilidade e estipulações:

1. C++ não fornece APIs específicas para refletir nos tipos de tempo de execução do Windows, mas os arquivos de metadados do Windows (. winmd) para um tipo são totalmente compatíveis com os arquivos de metadados do CLR. O Windows fornece as novas APIs de descoberta de metadados (RoGetMetaDataFile) para acessar o arquivo .winmd de um determinado tipo. No entanto, essas APIs são de uso limitado para os desenvolvedores C++ porque você não pode instanciar uma classe.

1. Após a compilação do código, você também precisará passar Runtimeobject.lib e Rometadata.lib ao Vinculador.

1. Este snippet é apresentado no estado em que se encontra. Embora seja esperado que funcione corretamente, ele pode conter erros.

```cpp
#include <hstring.h>
#include <cor.h>
#include <rometadata.h>
#include <rometadataresolution.h>
#include <collection.h>

namespace ABI_Isolation_Workaround {
    #include <inspectable.h>
    #include <WeakReference.h>
}
using namespace ABI_Isolation_Workaround;
#include <wrl/client.h>

using namespace Microsoft::WRL;
using namespace Windows::Foundation::Collections;

IVector<String^>^ GetTypeMethods(Object^);

MainPage::MainPage()
{
    InitializeComponent();

    Windows::Foundation::Uri^ uri = ref new Windows::Foundation::Uri("http://buildwindows.com/");
    auto methods = GetTypeMethods(uri);

    std::wstring strMethods;
    std::for_each(begin(methods), end(methods), [&strMethods](String^ methodName) {
        strMethods += methodName->Data();
        strMethods += L"\n";
    });

    wprintf_s(L"%s\n", strMethods.c_str());
}

IVector<String^>^ GetTypeMethods(Object^ instance)
{
    HRESULT hr;
    HSTRING hStringClassName;
    hr = instance->__cli_GetRuntimeClassName(reinterpret_cast<__cli_HSTRING__**>(&hStringClassName)); // internal method name subject to change post BUILD
    if (FAILED(hr))
        __cli_WinRTThrowError(hr); // internal method name subject to change post BUILD
    String^ className = reinterpret_cast<String^>(hStringClassName);

    ComPtr<IMetaDataDispenserEx> metadataDispenser; ComPtr<IMetaDataImport2> metadataImport; hr = MetaDataGetDispenser(CLSID_CorMetaDataDispenser, IID_IMetaDataDispenser, (LPVOID*)metadataDispenser.GetAddressOf());
    if (FAILED(hr))
        __cli_WinRTThrowError(hr); // internal method name subject to change post BUILD

    HSTRING hStringFileName;
    mdTypeDef typeDefToken;
    hr = RoGetMetaDataFile(hStringClassName, metadataDispenser.Get(), &hStringFileName, &metadataImport, &typeDefToken);
    if (FAILED(hr))
        __cli_WinRTThrowError(hr); // internal method name subject to change post BUILD
    String^ fileName = reinterpret_cast<String^>(hStringFileName);

    HCORENUM hCorEnum = 0;
    mdMethodDef methodDefs[2048];
    ULONG countMethodDefs = sizeof(methodDefs);
    hr = metadataImport->EnumMethods(&hCorEnum, typeDefToken, methodDefs, countMethodDefs,  &countMethodDefs);
    if (FAILED(hr))
        __cli_WinRTThrowError(hr); // internal method name subject to change post BUILD

    wchar_t methodName[1024];
    ULONG countMethodName;
    std::wstring strMethods;
    Vector<String^>^ retVal = ref new Vector<String^>();

    for (int i = 0; i < countMethodDefs; ++i)
    {
        countMethodName = sizeof(methodName);
        hr = metadataImport->GetMethodProps(methodDefs[i], nullptr, methodName, countMethodName, &countMethodName, nullptr, nullptr, nullptr, nullptr, nullptr);
        if (SUCCEEDED(hr))
        {
            methodName[ countMethodName ] = 0;
            retVal->Append(ref new String(methodName));
        }
    }
    return retVal;
}
```

## <a name="see-also"></a>Consulte também

[Interoperando com outras linguagens](interoperating-with-other-languages-c-cx.md)
