---
title: DLLs MFC regulares vinculadas dinamicamente a MFC | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- regular MFC DLLs [C++], dynamically linked to MFC
- AFX_MANAGE_STATE macro
- DLLs [C++], regular
- shared DLL versions [C++]
- dynamically linked DLLs [C++]
ms.assetid: b4f7ab92-8723-42a5-890e-214f4e29dcd0
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 930d56f7bc296225e6fefcf92e49087a2aed99cb
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="regular-mfc-dlls-dynamically-linked-to-mfc"></a>DLLs MFC regulares vinculadas dinamicamente a MFC
Uma expressão de que dll MFC vinculada dinamicamente a MFC é uma DLL que usa MFC internamente e as funções exportadas na DLL podem ser chamadas por arquivos executáveis do MFC ou não MFC. Como o nome descreve, esse tipo de DLL é criado usando a versão da biblioteca de vínculo dinâmico do MFC (também conhecido como a versão compartilhada do MFC). Funções normalmente são exportadas de uma DLL do MFC usando a interface padrão do C regular.  
  
 Você deve adicionar o `AFX_MANAGE_STATE` macro no início de todas as funções exportadas DLLs normais do MFC que vincular dinamicamente a MFC para definir o estado atual do módulo para o outro para a DLL. Isso é feito adicionando a seguinte linha de código para o início da função DLL exportada:  
  
```  
AFX_MANAGE_STATE(AfxGetStaticModuleState( ))  
```  
  
 Regular DLL do MFC, vinculada dinamicamente a MFC tem os seguintes recursos:  
  
-   Isso é um novo tipo de DLL introduzido pelo Visual C++ 4.0.  
  
-   O executável do cliente pode ser escrito em qualquer linguagem compatível com o uso de DLLs (C, C++, Pascal, Visual Basic e assim por diante); ele não precisa ser um aplicativo MFC.  
  
-   Ao contrário de DLL MFC regular estaticamente vinculado, esse tipo de DLL está dinamicamente vinculado para a DLL do MFC (também conhecido como a DLL do MFC compartilhado).  
  
-   A biblioteca de importação do MFC vinculada a este tipo de DLL é o mesmo usado para DLLs de extensão do MFC ou aplicativos que usam a DLL do MFC:. lib de MFCxx (D).  
  
 Regular DLL do MFC, vinculada dinamicamente a MFC tem os seguintes requisitos:  
  
-   Essas DLLs são compilados com **_AFXDLL** definido, como um executável que está dinamicamente vinculado para a DLL do MFC. Mas **usrdll** também está definida como uma DLL MFC regular que está estaticamente vinculada ao MFC.  
  
-   Esse tipo de DLL deve instanciar um `CWinApp`-classe derivada.  
  
-   Esse tipo de DLL usará o `DllMain` fornecido pelo MFC. Coloque todo código de inicialização específica de DLL no `InitInstance` código de função e encerramento de membro em `ExitInstance` como um aplicativo MFC normal.  
  
 Como esse tipo de DLL usa a versão da biblioteca de vínculo dinâmico do MFC, você deve definir explicitamente o estado atual do módulo para o outro para a DLL. Para fazer isso, use o [AFX_MANAGE_STATE](../mfc/reference/extension-dll-macros.md#afx_manage_state) macro no início de cada função exportado da DLL.  
  
 DLLs normais do MFC deve ter um `CWinApp`-derivado de classe e um único objeto dessa classe de aplicativo, como um aplicativo do MFC. No entanto, o `CWinApp` o objeto da DLL não tem uma bomba de mensagem principal, como faz o `CWinApp` objeto de um aplicativo.  
  
 Observe que o `CWinApp::Run` mecanismo não se aplica a uma DLL, porque o aplicativo que detém a bomba de mensagem principal. Se sua DLL abre caixas de diálogo sem janela restrita ou tem uma janela do quadro principal de seu próprio, bomba de mensagem principal do seu aplicativo deve chamar uma rotina DLL exportada que chama `CWinApp::PreTranslateMessage`.  
  
 Coloque todos os inicialização específica de DLL no `CWinApp::InitInstance` a função de membro como um aplicativo MFC normal. O `CWinApp::ExitInstance` função membro de sua `CWinApp` classe derivada é chamado a partir de MFC fornecido `DllMain` funcionar antes que a DLL é descarregada.  
  
 Você deve distribuir o MFCx0.dll de DLLs compartilhadas e Msvcr*0.dll (ou arquivos similares) com o seu aplicativo.  
  
 Uma DLL que está vinculada dinamicamente ao MFC também estaticamente não é possível vincular a MFC. Link de aplicativos para DLLs normais do MFC vinculadas dinamicamente a MFC-lo como qualquer outro DLL.  
  
 Símbolos geralmente são exportados de uma DLL do MFC usando a interface padrão do C regular. A declaração de uma função exportada de uma DLL MFC regular parecida com esta:  
  
```  
extern "C" __declspec(dllexport) MyExportedFunction( );  
```  
  
 Todas as alocações de memória dentro de uma DLL MFC regular devem permanecer na DLL; a DLL não deve passar para ou receber o executável de chamar qualquer um dos seguintes:  
  
-   ponteiros para objetos MFC  
  
-   ponteiros para a memória alocada pelo MFC  
  
 Se você precisar fazer qualquer uma das opções acima, ou se você precisar passar objetos derivados de MFC entre o executável de chamada e a DLL, você deve criar uma DLL de extensão do MFC.  
  
 É seguro passar ponteiros de memória que foram alocados pelas bibliotecas de tempo de execução do C entre um aplicativo e uma DLL somente se você fizer uma cópia dos dados. Você não deve excluir ou redimensionar esses ponteiros ou usá-los sem fazer uma cópia da memória.  
  
 Ao criar uma DLL MFC regular que dinamicamente vinculado ao MFC, você precisa usar a macro [AFX_MANAGE_STATE](../mfc/reference/extension-dll-macros.md#afx_manage_state) para alternar o estado do módulo MFC corretamente. Isso é feito adicionando a seguinte linha de código para o início da função DLL exportada:  
  
```  
AFX_MANAGE_STATE(AfxGetStaticModuleState( ))  
```  
  
 O **AFX_MANAGE_STATE** macro não deve ser usada em DLLs normais do MFC estaticamente vinculadas a MFC ou em DLLs de extensão do MFC. Para obter mais informações, consulte [Gerenciando os dados de estado de módulos de MFC](../mfc/managing-the-state-data-of-mfc-modules.md).  
  
 Para obter um exemplo de como gravar, criar e usar uma DLL MFC regular, consulte o exemplo [DLLScreenCap](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/MFC/advanced/DllScreenCap). Para obter mais informações sobre DLLs normais do MFC que vincular dinamicamente a MFC, consulte a seção intitulada "Convertendo DLLScreenCap para dinamicamente Link com a DLL do MFC" em resumo para o exemplo.  
  
## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?  
  
-   [Inicializar a DLLs normais do MFC](../build/run-time-library-behavior.md#initializing-regular-dlls)  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [Os estados de módulo de uma DLL MFC regular vinculada dinamicamente ao MFC](../build/module-states-of-a-regular-dll-dynamically-linked-to-mfc.md)  
  
-   [Gerenciando os dados de estado dos módulos MFC](../mfc/managing-the-state-data-of-mfc-modules.md)  
  
-   [Usando banco de dados, OLE e DLLs de extensão de MFC de soquetes em DLLs MFC regulares](../build/using-database-ole-and-sockets-extension-dlls-in-regular-dlls.md)  
  
-   [Usando MFC como parte de uma DLL](../mfc/tn011-using-mfc-as-part-of-a-dll.md)  
  
## <a name="see-also"></a>Consulte também  
 [Tipos de DLLs](../build/kinds-of-dlls.md)