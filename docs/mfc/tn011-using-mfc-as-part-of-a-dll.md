---
title: "TN011: usando MFC como parte de uma DLL | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.mfc.dll"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Símbolo _USRDLL"
  - "DLLs [C++], vinculando"
  - "DLLs MFC [C++], vinculando DLLs regulares a MFC"
  - "TN011"
  - "USRDLLs, opções de compilador"
ms.assetid: 76753e9c-59dc-40f6-b6a7-f6bb9a7c4190
caps.latest.revision: 20
caps.handback.revision: 16
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN011: usando MFC como parte de uma DLL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Essa observação descreve as dlls normais, que permitem que você use a biblioteca MFC como parte de uma biblioteca de vínculo dinâmico\) nativa \(DLL\) do windows.  Supõe que você esteja familiarizado com as dlls do windows e como os criar.  Para obter informações sobre dlls de extensão MFC, que você pode criar extensões para a biblioteca MFC, consulte [Versão da DLL MFC](../mfc/tn033-dll-version-of-mfc.md).  
  
## Interfaces de DLL  
 Dlls assumem interfaces normais entre o aplicativo e o DLL são especificados em 2.0 \- c como funções ou classes explicitamente exportadas.  As interfaces da classe de MFC não podem ser exportadas.  
  
 Se uma DLL e um aplicativo querem usar o MFC, tem uma opção para usar a versão compartilhada as bibliotecas de MFC ou a estaticamente vincular a uma cópia das bibliotecas.  O aplicativo e o DLL ambos podem usar uma das versões padrão de biblioteca MFC.  
  
 Dlls normais têm várias vantagens:  
  
-   O aplicativo que usa a DLL não tem que usar o MFC e não precisa ser um aplicativo do Visual C\+\+.  
  
-   A DLL regulares que vinculam estaticamente MFC ao, o tamanho da DLL depende apenas as rotinas de tempo de execução e MFC de C que 2.0 são usadas e vinculadas.  
  
-   A DLL regulares que vinculam dinamicamente ao MFC, o aumento na memória de usar a versão compartilhada MFC podem ser significativas.  Porém, você deve distribuir as dlls, o Mfc*\<version\>*.dll e o Msvvcrt compartilhados*\<version\>*.dll, com a DLL.  
  
-   O design da DLL é independente de como as classes são implementadas.  O design da DLL exportar apenas a APIs que você deseja.  No resultado, se a implementação for alterado, as dlls normais ainda serão válidos.  
  
-   A DLL regulares que vinculam estaticamente ao MFC, se a DLL e o aplicativo usam o MFC, não há nenhum problema com o aplicativo que deseja uma versão diferente de MFC que o DLL ou vice\-versa.  Como a biblioteca MFC estiver vinculada estaticamente em cada DLL ou em EXE, não há necessidade sobre qual versão você tiver.  
  
## Limitações de API  
 Algumas funcionalidades MFC não se aplica a versão da DLL, ou devido às limitações técnicas ou porque esses serviços normalmente são fornecidos pelo aplicativo.  Com a versão atual de MFC, a única função que não é aplicável. é `CWinApp::SetDialogBkColor`  
  
## Criando o DLL  
 Ao criar as dlls regulares que vinculam estaticamente MFC ao, os símbolos `_USRDLL` e a `_WINDLL` deve ser definido.  O código da DLL também deve ser compilado com as seguintes opções do compilador:  
  
-   **\/D\_WINDLL** significa a compilação é para uma DLL  
  
-   **\/D\_USRDLL** especificar estiver criando uma DLL normal  
  
 Você também deve definir esses símbolos e usar essas opções do compilador quando você cria o DLL regulares que vinculam dinamicamente ao MFC.  Além disso, o símbolo `_AFXDLL` deve ser definido e seu código DLL deve ser compilado com:  
  
-   **\/D\_AFXDLL** especifica que você está criando uma DLL normal que vincula dinamicamente ao MFC  
  
 Interfaces \(APIs\) entre o aplicativo e o DLL deve ser exportadas.  Recomendamos que você define suas interfaces para ser largura de banda baixa, e usar apenas 2.0 C interfaces se puder.  As interfaces C são mais fáceis de manter uma das classes mais complexas C\+\+.  
  
 Colocar as APIs em um cabeçalho separado que pode ser incluído pelos arquivos de 2.0 C e C\+\+.  Consulte o cabeçalho ScreenCap.h nos conceitos avançados MFC [DLLScreenCap](../top/visual-cpp-samples.md) de exemplo para obter um exemplo.  Para exportar suas funções, incorpore\-as na seção de `EXPORTS` do arquivo de definição de módulo \(.DEF\) ou o inclua `__declspec(dllexport)` em suas definições de função.  Use `__declspec(dllimport)` para importar essas funções no executável do cliente.  
  
 Você deve adicionar a macro de `AFX_MANAGE_STATE` no início de todas as funções exportadas na DLL regulares que vinculam dinamicamente ao MFC.  Esta macro define o estado atual do módulo ao para a DLL.  Para usar esta macro, adicione a seguinte linha de código ao início das funções exportadas da DLL:  
  
 `AFX_MANAGE_STATE(AfxGetStaticModuleState( ))`  
  
## WinMain \-\> DllMain  
 A biblioteca MFC define o ponto de entrada padrão do Win32 `DllMain` que inicializa o objeto derivado [CWinApp](../mfc/reference/cwinapp-class.md) como em um aplicativo típico MFC.  Colocar qualquer inicialização DLL\- específica no método de [InitInstance](../Topic/CWinApp::InitInstance.md) como em um aplicativo típico MFC.  
  
 Observe que o mecanismo de [CWinApp::Run](../Topic/CWinApp::Run.md) não se aplica a uma DLL, porque o aplicativo possuir a bomba principal da mensagem.  Se o DLL exibe caixas de diálogo modeless ou tem uma janela principal do quadro de sua escolha, a bomba principal da mensagem do seu aplicativo deve chamar uma rotina DLL\- exportada que chama [CWinApp::PreTranslateMessage](../Topic/CWinApp::PreTranslateMessage.md).  
  
 Consulte o exemplo de DLLScreenCap para o uso dessa função.  
  
 A função de `DllMain` que o MFC fornece chamará o método de [CWinApp::ExitInstance](../Topic/CWinApp::ExitInstance.md) da sua classe que é derivada de `CWinApp` antes que o DLL seja descarregado.  
  
## Vinculando o DLL  
 A DLL regulares que vinculam estaticamente MFC ao, você deve vincular seu DLL com Nafxcwd.lib ou Nafxcw.lib e com a versão do tempo de execução C Libcmt.lib nomeada.  Essas bibliotecas previamente são compilados e podem ser feitas especificando o quando você executar a instalação do Visual C\+\+.  
  
## Código de Exemplo  
 Consulte os conceitos avançados MFC o programa de exemplo DLLScreenCap para obter um exemplo completo.  Vários fatos interessantes a observe neste exemplo são os seguintes:  
  
-   Os sinalizadores do compilador DLL e as opções do aplicativo são diferentes.  
  
-   As linhas do link e os arquivos de .DEF para a DLL e os planos para o aplicativo são diferentes.  
  
-   O aplicativo que usa a DLL não tem que estar em C\+\+.  
  
-   A interface entre o aplicativo e o DLL é uma API que é útil por 2.0 por C ou C\+\+ e é exportado com DLLScreenCap.def.  
  
 O exemplo a seguir ilustra a API que é definido em uma DLL normal que vincula estaticamente MFC ao.  Neste exemplo, a declaração é incluída em um bloco de `extern "C" { }` para usuários C\+\+.  Isso tem várias vantagens.  Primeiro, faz as APIs da DLL úteis por aplicativos cliente de non\-C\+\+.  Segundo, reduz a sobrecarga da DLL como o nome de massacre C\+\+ não será aplicado ao nome exportado.  Finalmente, facilita adicionar explicitamente a um arquivo de .DEF \(para exportar por ordinal\) sem se preocupar sobre o massacre do nome.  
  
```  
#ifdef __cplusplus  
extern "C" {  
#endif  /* __cplusplus */  
  
struct TracerData  
{  
    BOOL    bEnabled;  
    UINT    flags;  
};  
  
BOOL PromptTraceFlags(TracerData FAR* lpData);  
  
#ifdef __cplusplus  
}  
#endif  
```  
  
 As estruturas usadas pela API não são derivadas das classes MFC e são definidas no cabeçalho da API.  Isso reduz a complexidade da interface entre o DLL e o aplicativo e faz a DLL útil por programas de 2.0 c.  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)