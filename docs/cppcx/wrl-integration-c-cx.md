---
title: "Integração WRL (C + + CX) | Microsoft Docs"
ms.custom: 
ms.date: 01/22/2017
ms.technology: cpp-windows
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 3ad43894-c574-477c-ad3e-240301f381d4
caps.latest.revision: "9"
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 859a25f4fc9698899f1139038e161d28da06220e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="wrl-integration-ccx"></a>Integração WRL (C++/CX)

Você pode combinar livremente o código de WRL com [!INCLUDE[cppwrl](includes/cppwrl-md.md)] ([!INCLUDE[cppwrl_short](includes/cppwrl-short-md.md)]) código. Na mesma unidade de tradução, você pode usar objetos declarados com WRL handle-to-object (`^`) notação e [!INCLUDE[cppwrl_short](includes/cppwrl-short-md.md)] ponteiro inteligente (`ComPtr<T>`) notação. No entanto, você deve tratar manualmente os valores de retorno, e [!INCLUDE[cppwrl_short](includes/cppwrl-short-md.md)] HRESULT exceções de WRL e códigos de erro.
  
## <a name="includecppwrlshortincludescppwrl-short-mdmd-development"></a>Desenvolvimento do[!INCLUDE[cppwrl_short](includes/cppwrl-short-md.md)] 

Para obter mais informações sobre criação e consumo [!INCLUDE[cppwrl_short](includes/cppwrl-short-md.md)] componentes, consulte [biblioteca de modelo em C++ Windows Runtime (WRL)](../windows/windows-runtime-cpp-template-library-wrl.md).

### <a name="example"></a>Exemplo

O trecho de código a seguir demonstra como usar WRL e [!INCLUDE[cppwrl_short](includes/cppwrl-short-md.md)] consumir [!INCLUDE[wrt](includes/wrt-md.md)] classes e examinar um arquivo de metadados.

O exemplo é obtido de um trecho de código no [Fórum de aplicativos da Windows Store](http://social.msdn.microsoft.com/Forums/winappswithnativecode/thread/211ef583-db11-4e55-926b-6d9ab53dbdb4). O autor desse trecho de código oferece os seguintes avisos de isenção de responsabilidade e estipulações:

1. O C++ não fornece APIs específicas para refletir nos tipos [!INCLUDE[wrt](includes/wrt-md.md)] , mas os arquivos de metadados do Windows (.winmd) de um tipo são totalmente compatíveis com os arquivos de metadados CLR. O Windows fornece as novas APIs de descoberta de metadados (RoGetMetaDataFile) para acessar o arquivo .winmd de um determinado tipo. No entanto, essas APIs são de uso limitado para os desenvolvedores C++ porque você não pode instanciar uma classe.

1. Após a compilação do código, você também precisará passar Runtimeobject.lib e Rometadata.lib ao Vinculador.

1. Este trecho é apresentado no estado em que se encontra. Embora seja esperado que funcione corretamente, ele pode conter erros.

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
