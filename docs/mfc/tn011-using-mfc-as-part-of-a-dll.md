---
title: 'TN011: Usando MFC como parte de uma DLL'
ms.date: 11/04/2016
f1_keywords:
- vc.mfc.dll
helpviewer_keywords:
- _USRDLL symbol
- USRDLLs, compiler switches
- TN011
- DLLs [MFC], linking
- MFC DLLs [MFC], linking regular MFC DLLs to MFC
ms.assetid: 76753e9c-59dc-40f6-b6a7-f6bb9a7c4190
ms.openlocfilehash: 7e9fda44e2af4ec32bae6299fbcc0eda17984f9b
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58769726"
---
# <a name="tn011-using-mfc-as-part-of-a-dll"></a>TN011: Usando MFC como parte de uma DLL

Essa observação descreve DLLs normais do MFC, que permitem que você use a biblioteca do MFC como parte de uma biblioteca de vínculo dinâmico (DLL) do Windows. Ele pressupõe que você esteja familiarizado com DLLs do Windows e como criá-los. Para obter informações sobre DLLs de extensão do MFC, com o qual você pode criar extensões para a biblioteca do MFC, consulte [versão de DLL do MFC](../mfc/tn033-dll-version-of-mfc.md).

## <a name="dll-interfaces"></a>DLL Interfaces

DLLs MFC regulares pressupõem interfaces entre o aplicativo e a DLL são especificados em C como funções ou classes exportadas explicitamente. Interfaces de classe do MFC não podem ser exportados.

Se quiserem que uma DLL e um aplicativo usar o MFC, têm uma opção para usar a versão compartilhada das bibliotecas MFC ou para um link estático para uma cópia das bibliotecas. O aplicativo e a DLL podem ambos usam uma das versões padrão da biblioteca MFC.

DLLs MFC regulares tem várias vantagens:

- O aplicativo que usa a DLL não precisa usar o MFC e não precisa ser um aplicativo do Visual C++.

- Com DLLs MFC regulares vinculadas estaticamente ao MFC, o tamanho da DLL depende somente as rotinas de tempo de execução MFC e C que são usadas e vinculadas.

- Com DLLs MFC regulares vinculadas dinamicamente ao MFC, a economia na memória do uso da versão compartilhada de MFC poderá ser significativa. No entanto, você deve distribuir as DLLs compartilhadas, Mfc\<*versão*>. dll e Msvvcrt\<*versão*>. dll, com sua DLL.

- O projeto DLL é independente de como as classes são implementadas. Seu projeto DLL exporta somente para as APIs que você deseja. Como resultado, se a implementação for alterado, DLLs MFC regulares ainda são válidas.

- Com DLLs MFC regulares vinculadas estaticamente ao MFC, se a DLL e o aplicativo usam o MFC, não há nenhum problema com o aplicativo que deseja que seja uma versão diferente do MFC que a DLL ou vice-versa. Como a biblioteca do MFC está vinculada estaticamente para cada DLL ou EXE, não há nenhuma pergunta sobre qual versão você tem.

## <a name="api-limitations"></a>Limitações de API

Algumas funcionalidades do MFC não se aplica à versão DLL, devido à limitações técnicas ou porque esses serviços são geralmente fornecidos pelo aplicativo. Com a versão atual do MFC, a única função que não é aplicável é `CWinApp::SetDialogBkColor`.

## <a name="building-your-dll"></a>Criar sua DLL

Ao compilar DLLs MFC regulares que se vinculam estaticamente ao MFC, os símbolos `_USRDLL` e `_WINDLL` deve ser definido. O código DLL também deve ser compilado com as seguintes opções do compilador:

- **/ D_WINDLL** significa a compilação é para uma DLL

- **/ D_USRDLL** Especifica que você está criando uma DLL MFC regular

Você também deve definir esses símbolos e usar essas opções de compilador ao compilar DLLs MFC regulares vinculadas dinamicamente ao MFC. Além disso, o símbolo `_AFXDLL` deve ser definido e seu código DLL deve ser compilado com:

- **/ D_AFXDLL** Especifica que você está compilando uma DLL MFC regular que vincula dinamicamente ao MFC

As APIs (interfaces) entre o aplicativo e a DLL devem ser exportadas explicitamente. É recomendável que você defina suas interfaces para ser baixa largura de banda e usa somente as interfaces de C, se possível. Interfaces de C diretas são mais fáceis de manter que classes mais complexas do C++.

Coloque suas APIs em um cabeçalho separado que pode ser incluído em arquivos C e C++. Consulte o cabeçalho ScreenCap.h no exemplo de conceitos avançados MFC [DLLScreenCap](../overview/visual-cpp-samples.md) para obter um exemplo. Para exportar suas funções, inseri-los a `EXPORTS` seção do seu arquivo de definição de módulo (. DEF) ou incluir `__declspec(dllexport)` em suas definições de função. Use `__declspec(dllimport)` para importar essas funções para o executável do cliente.

Você deve adicionar o macro AFX_MANAGE_STATE no início de todas as funções exportadas em DLLs MFC regulares vinculadas dinamicamente ao MFC. Essa macro define o estado atual do módulo para aquele para a DLL. Para usar essa macro, adicione a seguinte linha de código para o início das funções exportadas da DLL:

`AFX_MANAGE_STATE(AfxGetStaticModuleState( ))`

## <a name="winmain---dllmain"></a>WinMain -> DllMain

A biblioteca MFC define Win32 padrão `DllMain` ponto de entrada que inicializa sua [CWinApp](../mfc/reference/cwinapp-class.md) derivados do objeto como um aplicativo típico do MFC. Coloque todos os inicialização específica de DLL na [InitInstance](../mfc/reference/cwinapp-class.md#initinstance) método como em um aplicativo típico do MFC.

Observe que o [CWinApp:: Run](../mfc/reference/cwinapp-class.md#run) mecanismo não se aplica a uma DLL, porque o aplicativo que detém a bomba de mensagem principal. Se sua DLL exibe as caixas de diálogo sem janela restrita ou tem uma janela de quadro principal de seu próprio, bomba de mensagem principal do seu aplicativo deve chamar uma rotina de DLL exportada que chama [CWinApp::PreTranslateMessage](../mfc/reference/cwinapp-class.md#pretranslatemessage).

Consulte o exemplo de DLLScreenCap do uso dessa função.

O `DllMain` função MFC fornece chamará o [CWinApp::ExitInstance](../mfc/reference/cwinapp-class.md#exitinstance) método de sua classe derivada de `CWinApp` antes que a DLL seja descarregada.

## <a name="linking-your-dll"></a>Vincular seu DLL

Com DLLs MFC regulares vinculadas estaticamente ao MFC, você deve vincular sua DLL com Nafxcwd. lib ou Nafxcw.lib e com a versão dos tempos de execução C chamadas libcmt. lib. Essas bibliotecas são criadas previamente e podem ser instaladas, especificando-os ao executar a instalação do Visual C++.

## <a name="sample-code"></a>Código de exemplo

Consulte o exemplo de conceitos avançados MFC DLLScreenCap do programa para um exemplo completo. Várias coisas interessantes a observar neste exemplo são da seguinte maneira:

- Os sinalizadores de compilador da DLL e aqueles do aplicativo são diferentes.

- As linhas de link e. Arquivos DEF da dll e aquelas para o aplicativo são diferentes.

- O aplicativo que usa a DLL não precisa estar no C++.

- A interface entre o aplicativo e a DLL é uma API que pode ser usado por C ou C++ e é exportada com DLLScreenCap.def.

O exemplo a seguir ilustra uma API que é definida em uma DLL do MFC que se vincula estaticamente ao MFC regular. Neste exemplo, a declaração é colocada entre um `extern "C" { }` bloco para usuários do C++. Isso tem várias vantagens. Primeiro, ele faz suas APIs de DLL utilizável por aplicativos cliente não C++. Em segundo lugar, ele reduz a sobrecarga DLL porque a desconfiguração do nome de C++ não será aplicada para o nome exportado. Por fim, ela torna mais fácil adicionar explicitamente a um. Arquivo DEF (para exportação por ordinal) sem precisar se preocupar sobre a desconfiguração de nome.

```
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

As estruturas usadas pela API não são derivadas de classes do MFC e são definidas no cabeçalho da API. Isso reduz a complexidade da interface entre o aplicativo e a DLL e faz com que a DLL utilizável por programas C.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
