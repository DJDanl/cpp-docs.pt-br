---
title: 'TN011: Usando MFC como parte de uma DLL | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.mfc.dll
dev_langs:
- C++
helpviewer_keywords:
- _USRDLL symbol
- USRDLLs, compiler switches
- TN011
- DLLs [MFC], linking
- MFC DLLs [MFC], linking regular MFC DLLs to MFC
ms.assetid: 76753e9c-59dc-40f6-b6a7-f6bb9a7c4190
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0dcaa0aaf903787549cc91ffd19a34aa4aa066bd
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="tn011-using-mfc-as-part-of-a-dll"></a>TN011: usando MFC como parte de uma DLL
Esta anotação descreve DLLs normais do MFC, que permitem que você use a biblioteca do MFC como parte de uma biblioteca de vínculo dinâmico (DLL) do Windows. Ele pressupõe que você esteja familiarizado com DLLs do Windows e como criá-los. Para obter informações sobre DLLs de extensão do MFC, com a qual você pode criar extensões para a biblioteca do MFC, consulte [versão de DLL do MFC](../mfc/tn033-dll-version-of-mfc.md).  
  
## <a name="dll-interfaces"></a>Interfaces DLL  
 DLLs normais do MFC suponha interfaces entre o aplicativo e a DLL são especificadas em funções de C ou classes explicitamente exportados. Interfaces de classe do MFC não podem ser exportados.  
  
 Se uma DLL e um aplicativo usar MFC, têm uma opção de usar a versão compartilhada das bibliotecas MFC ou link estático para uma cópia das bibliotecas. O aplicativo e a DLL podem ambos usam uma das versões padrão da biblioteca do MFC.  
  
 DLLs normais do MFC tem várias vantagens:  
  
-   O aplicativo que usa a DLL não precisa usar MFC e não precisa ser um aplicativo do Visual C++.  
  
-   DLLs MFC regulares vinculados estaticamente ao MFC, o tamanho da DLL depende apenas as rotinas de tempo de execução MFC e C que são usadas e vinculadas.  
  
-   DLLs MFC regular que vincular dinamicamente a MFC, o aumento na memória usa a versão compartilhada do MFC pode ser significativo. No entanto, você deve distribuir as DLLs compartilhadas, Mfc*\<versão >*. dll e Msvvcrt*\<versão >*. dll, com sua DLL.  
  
-   O projeto DLL é independente de como as classes são implementadas. O projeto DLL exporta apenas para as APIs que você deseja. Como resultado, se a implementação for alterada, as DLLs normais do MFC ainda são válidas.  
  
-   DLLs MFC regulares vinculados estaticamente ao MFC, se a DLL e o aplicativo usarem MFC, não há nenhum problema com o aplicativo que deseja que seja uma versão diferente do MFC que a DLL ou vice-versa. Porque a biblioteca do MFC estaticamente vinculada para cada DLL ou EXE, não há nenhuma pergunta sobre qual versão você tem.  
  
## <a name="api-limitations"></a>Limitações de API  
 Algumas funcionalidades do MFC não se aplica à versão DLL, devido à limitações técnicas ou porque esses serviços normalmente são fornecidos pelo aplicativo. Com a versão atual do MFC, a única função que não é aplicável é `CWinApp::SetDialogBkColor`.  
  
## <a name="building-your-dll"></a>Criando a DLL  
 Ao compilar a DLLs normais do MFC estaticamente vinculadas a MFC, os símbolos `_USRDLL` e `_WINDLL` devem ser definidas. O código DLL também deve ser compilado com as seguintes opções do compilador:  
  
- **/ D_WINDLL** significa que a compilação é para uma DLL  
  
- **/ D_USRDLL** Especifica a compilação de uma DLL MFC regular  
  
 Você também deve definir esses símbolos e usar essas opções de compilador quando você compila DLLs normais do MFC que vincular dinamicamente a MFC. Além disso, o símbolo `_AFXDLL` devem ser definidos e seu código DLL deve ser compilado com:  
  
- **/ D_AFXDLL** Especifica que você está criando uma DLL MFC regular vinculada dinamicamente a MFC  
  
 As APIs (interfaces) entre o aplicativo e a DLL devem ser exportadas explicitamente. É recomendável que você define as interfaces para ser baixa largura de banda e use somente as interfaces de C, se possível. Interfaces de C diretos são mais fáceis de manter de classes C++ mais complexas.  
  
 Coloque suas APIs em um cabeçalho separado que pode ser incluído por arquivos C e C++. Consulte o cabeçalho ScreenCap.h no exemplo de conceitos avançados do MFC [DLLScreenCap](../visual-cpp-samples.md) para obter um exemplo. Para exportar suas funções, inseri-los a `EXPORTS` seção do seu arquivo de definição de módulo (. DEF) ou incluir `__declspec(dllexport)` em suas definições de função. Use `__declspec(dllimport)` para importar essas funções para o executável do cliente.  
  
 Você deve adicionar o `AFX_MANAGE_STATE` macro no início de todas as funções exportadas DLLs normais do MFC que vincular dinamicamente a MFC. Esta macro define o estado atual do módulo para o outro para a DLL. Para usar essa macro, adicione a seguinte linha de código para o início da função DLL exportada:  
  
 `AFX_MANAGE_STATE(AfxGetStaticModuleState( ))`  
  
## <a name="winmain---dllmain"></a>WinMain -> DllMain  
 A biblioteca do MFC define o padrão do Win32 `DllMain` ponto de entrada que inicializa o [CWinApp](../mfc/reference/cwinapp-class.md) derivados do objeto como um aplicativo típico do MFC. Coloque todos os inicialização específica de DLL no [InitInstance](../mfc/reference/cwinapp-class.md#initinstance) método como um aplicativo típico do MFC.  
  
 Observe que o [CWinApp:: Run](../mfc/reference/cwinapp-class.md#run) mecanismo não se aplica a uma DLL, porque o aplicativo que detém a bomba de mensagem principal. Se sua DLL exibe caixas de diálogo sem janela restrita ou tem uma janela do quadro principal de seu próprio, bomba de mensagem principal do seu aplicativo deve chamar uma rotina DLL exportada que chama [CWinApp::PreTranslateMessage](../mfc/reference/cwinapp-class.md#pretranslatemessage).  
  
 Consulte o exemplo DLLScreenCap para o uso dessa função.  
  
 O `DllMain` função MFC fornece chamará o [CWinApp::ExitInstance](../mfc/reference/cwinapp-class.md#exitinstance) método de sua classe derivada de `CWinApp` antes da DLL é descarregada.  
  
## <a name="linking-your-dll"></a>A DLL de vinculação  
 DLLs MFC regulares vinculados estaticamente ao MFC, você deve vincular sua DLL com Nafxcwd ou Nafxcw.lib e com a versão dos tempos de execução C denominados Libcmt.lib. Essas bibliotecas são predefinidas e podem ser instaladas, especificando-os ao executar a instalação do Visual C++.  
  
## <a name="sample-code"></a>Código de exemplo  
 Consulte o exemplo de conceitos avançados do MFC DLLScreenCap do programa para um exemplo completo. Vários fatos interessantes a observar neste exemplo são os seguintes:  
  
-   Os sinalizadores de compilador da DLL e aqueles do aplicativo são diferentes.  
  
-   As linhas de link e. Arquivos DEF para a DLL e para o aplicativo são diferentes.  
  
-   O aplicativo que usa a DLL não precisa estar em C++.  
  
-   A interface entre o aplicativo e a DLL é uma API que pode ser usado por C ou C++ e é exportada com DLLScreenCap.def.  
  
 O exemplo a seguir ilustra uma API que é definida em uma DLL do MFC que se vincula estaticamente ao MFC regular. Neste exemplo, a declaração está contida em um `extern "C" { }` bloco para os usuários do C++. Isso tem várias vantagens. Primeiro, ele faz suas APIs DLL utilizável por aplicativos cliente não C++. Em segundo lugar, reduz a sobrecarga de DLL porque a desconfiguração do nome de C++ não será aplicada para o nome exportado. Por fim, ele torna mais fácil adicionar explicitamente a um. Definição de arquivo (para exportação por ordinal) sem precisar se preocupar sobre desconfiguração do nome.  
  
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
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

