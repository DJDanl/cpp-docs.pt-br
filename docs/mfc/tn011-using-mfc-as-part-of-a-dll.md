---
title: 'TN011: usando MFC como parte de uma DLL'
ms.date: 11/04/2016
helpviewer_keywords:
- _USRDLL symbol
- USRDLLs, compiler switches
- TN011
- DLLs [MFC], linking
- MFC DLLs [MFC], linking regular MFC DLLs to MFC
ms.assetid: 76753e9c-59dc-40f6-b6a7-f6bb9a7c4190
ms.openlocfilehash: 0f4d4e2ed76a0fa5f8f775345fc672a1df055a39
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370434"
---
# <a name="tn011-using-mfc-as-part-of-a-dll"></a>TN011: usando MFC como parte de uma DLL

Esta nota descreve DLLs MFC regulares, que permitem que você use a biblioteca MFC como parte de uma biblioteca de links dinâmicos do Windows (DLL). Ele assume que você está familiarizado com DLLs do Windows e como construí-los. Para obter informações sobre DLLs de extensão MFC, com as quais você pode criar extensões para a biblioteca MFC, consulte [Versão DLL do MFC](../mfc/tn033-dll-version-of-mfc.md).

## <a name="dll-interfaces"></a>DLL Interfaces

DLLs MFC regulares assumem que as interfaces entre o aplicativo e o DLL são especificadas em funções semelhantes a C ou classes explicitamente exportadas. As interfaces de classe MFC não podem ser exportadas.

Se uma DLL e um aplicativo quiserem usar o MFC, ambos terão a opção de usar a versão compartilhada das bibliotecas MFC ou vincular-se estáticamente a uma cópia das bibliotecas. O aplicativo e a DLL podem usar uma das versões padrão da biblioteca MFC.

DLLs MFC regulares têm várias vantagens:

- O aplicativo que usa o DLL não precisa usar MFC e não precisa ser um aplicativo Visual C++..

- Com DLLs MFC regulares que se ligam esticamente ao MFC, o tamanho da DLL depende apenas das rotinas de tempo de execução MFC e C que são usadas e ligadas.

- Com DLLs MFC regulares que se conectam dinamicamente ao MFC, a economia na memória de usar a versão compartilhada do MFC pode ser significativa. No entanto, você deve distribuir as DLLs compartilhadas,\<*versão* Mfc>.dll e Msvvcrt\<*versão*>.dll, com o seu DLL.

- O design dll é independente de como as classes são implementadas. Seu design DLL exporta apenas para as APIs desejadas. Como resultado, se a implementação mudar, os DLLs MFC regulares ainda são válidos.

- Com DLLs MFC regulares que se conectam esticamente ao MFC, se tanto o DLL quanto o aplicativo usarem MFC, não há problemas com o aplicativo que deseja uma versão diferente do MFC do que a DLL ou vice-versa. Como a biblioteca MFC está estáticamente ligada a cada DLL ou EXE, não há dúvida sobre qual versão você tem.

## <a name="api-limitations"></a>Limitações da API

Algumas funcionalidades de MFC não se aplicam à versão DLL, seja por limitações técnicas ou porque esses serviços geralmente são fornecidos pelo aplicativo. Com a versão atual do MFC, a única `CWinApp::SetDialogBkColor`função que não é aplicável é .

## <a name="building-your-dll"></a>Construindo sua DLL

Ao compilar DLLs MFC regulares que se vinculam `_WINDLL` estáticamente ao MFC, os símbolos devem ser definidos. `_USRDLL` O código DLL também deve ser compilado com os seguintes switches de compilador:

- **/D_WINDLL** significa que a compilação é para um DLL

- **/D_USRDLL** especifica que você está construindo um DLL MFC regular

Você também deve definir esses símbolos e usar esses switches de compilação quando você compila DLLs MFC regulares que se vinculam dinamicamente ao MFC. Além disso, `_AFXDLL` o símbolo deve ser definido e seu código DLL deve ser compilado com:

- **/D_AFXDLL** especifica que você está construindo uma DLL MFC regular que se conecta dinamicamente ao MFC

As interfaces (APIs) entre o aplicativo e a DLL devem ser explicitamente exportadas. Recomendamos que você defina suas interfaces como de baixa largura de banda e use apenas interfaces C se puder. Interfaces C diretas são mais fáceis de manter do que classes C++ mais complexas.

Coloque suas APIs em um cabeçalho separado que pode ser incluído pelos arquivos C e C++. Consulte o cabeçalho ScreenCap.h na amostra De conceitos avançados do MFC [DLLScreenCap,](../overview/visual-cpp-samples.md) por exemplo. Para exportar suas funções, `EXPORTS` insira-as na seção do arquivo de definição do módulo (. DEF) ou `__declspec(dllexport)` incluir em suas definições de função. Use `__declspec(dllimport)` para importar essas funções para o executável do cliente.

Você deve adicionar a AFX_MANAGE_STATE macro no início de todas as funções exportadas em DLLs MFC regulares que se vinculam dinamicamente ao MFC. Esta macro define o estado atual do módulo como o da DLL. Para usar esta macro, adicione a seguinte linha de código ao início das funções exportadas da DLL:

`AFX_MANAGE_STATE(AfxGetStaticModuleState( ))`

## <a name="winmain---dllmain"></a>WinMain -> DllMain

A biblioteca MFC define o `DllMain` ponto de entrada padrão do Win32 que inicializa seu objeto derivado do [CWinApp](../mfc/reference/cwinapp-class.md) como em um aplicativo MFC típico. Coloque toda a inicialização específica da DLL no método [InitInstance](../mfc/reference/cwinapp-class.md#initinstance) como em um aplicativo MFC típico.

Observe que o [mecanismo CWinApp::Run](../mfc/reference/cwinapp-class.md#run) não se aplica a uma DLL, porque o aplicativo possui a bomba de mensagem principal. Se o DLL exibir diálogos de modelagem ou tiver uma janela de quadro principal própria, a bomba de mensagem principal do aplicativo deve chamar uma rotina exportada por DLL que chama [CWinApp::PreTranslateMessage](../mfc/reference/cwinapp-class.md#pretranslatemessage).

Consulte a amostra DLLScreenCap para o uso desta função.

A `DllMain` função que o MFC fornece chamará o método [CWinApp::ExitInstance](../mfc/reference/cwinapp-class.md#exitinstance) da sua classe que é derivado antes da `CWinApp` DLL ser descarregada.

## <a name="linking-your-dll"></a>Vinculando sua DLL

Com DLLs MFC regulares que se conectam esticamente ao MFC, você deve vincular seu DLL com Nafxcwd.lib ou Nafxcw.lib e com a versão dos tempos de execução C chamado Libcmt.lib. Essas bibliotecas são pré-construídas e podem ser instaladas especificando-as quando você executa a configuração Visual C++..

## <a name="sample-code"></a>Exemplo de código

Consulte o programa de amostra MFC Advanced Concepts DLLScreenCap para obter uma amostra completa. Várias coisas interessantes a serem anotadas nesta amostra são as seguintes:

- As bandeiras de compilador da DLL e as da aplicação são diferentes.

- As linhas de ligação e . Os arquivos DEF para o DLL e os da aplicação são diferentes.

- O aplicativo que usa o DLL não precisa estar em C++.

- A interface entre o aplicativo e o DLL é uma API que é utilizável por C ou C++ e é exportada com DLLScreenCap.def.

O exemplo a seguir ilustra uma API definida em um DLL MFC regular que se liga estáticamente ao MFC. Neste exemplo, a declaração é `extern "C" { }` incluída em um bloco para usuários C++. Isso tem várias vantagens. Primeiro, torna suas APIs DLL utilizáveis por aplicativos clientes não C++. Em segundo lugar, reduz a sobrecarga de DLL porque o mangling de nome C++ não será aplicado ao nome exportado. Por último, torna mais fácil adicionar explicitamente a um . Arquivo DEF (para exportação por ordinal) sem ter que se preocupar com o mangling de nome.

```cpp
#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

struct TracerData
{
    BOOL bEnabled;
    UINT flags;
};

BOOL PromptTraceFlags(TracerData FAR* lpData);

#ifdef __cplusplus
}
#endif
```

As estruturas utilizadas pela API não são derivadas das classes MFC e são definidas no cabeçalho da API. Isso reduz a complexidade da interface entre a DLL e o aplicativo e torna a DLL utilizável por programas C.

## <a name="see-also"></a>Confira também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
