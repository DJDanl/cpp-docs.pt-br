---
title: DLLs MFC regular estatisticamente vinculadas a MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- regular MFC DLLs [C++]
- DLLs [C++], regular
- USRDLLs
- USRDLLs, statically linked to MFC
- statically linked DLLs [C++]
- regular MFC DLLs [C++], statically linked to MFC
ms.assetid: 2eed531c-726a-4b8a-b936-f721dc00a7fa
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c48fdfb0b10541c1643ec49038e29cfa60c633d9
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="regular-mfc-dlls-statically-linked-to-mfc"></a>DLLs MFC regular estatisticamente vinculadas a MFC
Uma expressão de que dll MFC vinculado estaticamente ao MFC é uma DLL que usa MFC internamente e as funções exportadas na DLL podem ser chamadas por arquivos executáveis do MFC ou não MFC. Como o nome descreve, esse tipo de DLL é criado usando a versão da biblioteca de vínculo estático do MFC. Funções normalmente são exportadas de uma DLL do MFC usando a interface padrão do C regular. Para obter um exemplo de como gravar, criar e usar uma DLL MFC regular, consulte o exemplo [DLLScreenCap](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/MFC/advanced/DllScreenCap).  
  
 Observe que o termo USRDLL não é usado na documentação do Visual C++. Uma DLL MFC regular que está estaticamente vinculada ao MFC tem as mesmas características que o antigo USRDLL.  
  
 Uma DLL MFC regular, estatisticamente vinculadas a MFC, tem os seguintes recursos:  
  
-   O executável do cliente pode ser escrito em qualquer linguagem compatível com o uso de DLLs (C, C++, Pascal, Visual Basic e assim por diante); ele não precisa ser um aplicativo MFC.  
  
-   A DLL pode vincular as mesmas bibliotecas de vínculo estático MFC usadas por aplicativos. Não é uma versão separada das bibliotecas de link estático para DLLs.  
  
-   Antes da versão 4.0 do MFC, USRDLLs fornecido o mesmo tipo de funcionalidade como DLLs normais do MFC vinculado estaticamente ao MFC. A partir do Visual C++ versão 4.0, o termo USRDLL está obsoleto.  
  
 Uma DLL MFC regular, estatisticamente vinculadas a MFC, tem os seguintes requisitos:  
  
-   Esse tipo de DLL deve instanciar uma classe derivada de `CWinApp`.  
  
-   Esse tipo de DLL usará o `DllMain` fornecido pelo MFC. Coloque todo código de inicialização específica de DLL no `InitInstance` código de função e encerramento de membro em `ExitInstance` como um aplicativo MFC normal.  
  
-   Embora o termo USRDLL está obsoleto, você ainda deve definir "**usrdll**" na linha de comando do compilador. Essa definição determina quais declarações é retirada dos arquivos de cabeçalho do MFC.  
  
 DLLs normais do MFC deve ter um `CWinApp`-derivado de classe e um único objeto dessa classe de aplicativo, como um aplicativo do MFC. No entanto, o `CWinApp` o objeto da DLL não tem uma bomba de mensagem principal, como faz o `CWinApp` objeto de um aplicativo.  
  
 Observe que o `CWinApp::Run` mecanismo não se aplica a uma DLL, porque o aplicativo que detém a bomba de mensagem principal. Se a DLL abre caixas de diálogo sem janela restrita ou tem uma janela do quadro principal de seu próprio, bomba de mensagem principal do aplicativo deve chamar uma rotina exportada pela DLL que por sua vez chama o `CWinApp::PreTranslateMessage` a função de membro de objeto de aplicativo da DLL.  
  
 Para obter um exemplo dessa função, consulte o exemplo de DLLScreenCap.  
  
 Símbolos geralmente são exportados de uma DLL do MFC usando a interface padrão do C regular. A declaração de uma função exportada de uma DLL MFC regular deve ter esta aparência:  
  
```  
extern "C" __declspec(dllexport) MyExportedFunction( );  
```  
  
 Todas as alocações de memória dentro de uma DLL MFC regular devem permanecer na DLL; a DLL não deve passar para ou receber o executável de chamar qualquer um dos seguintes:  
  
-   ponteiros para objetos MFC  
  
-   ponteiros para a memória alocada pelo MFC  
  
 Se você precisar executar qualquer uma das opções acima ou precisa passar objetos derivados de MFC entre o executável de chamada e a DLL, você deve criar uma DLL de extensão do MFC.  
  
 É seguro passar ponteiros de memória que foram alocados pelas bibliotecas de tempo de execução do C entre um aplicativo e uma DLL somente se você fizer uma cópia dos dados. Você não deve excluir ou redimensionar esses ponteiros ou usá-los sem fazer uma cópia da memória.  
  
 Uma DLL que está estaticamente vinculada ao MFC também dinamicamente não é possível vincular as DLLs compartilhada do MFC. Uma DLL que está estaticamente vinculada ao MFC dinamicamente está associada a um aplicativo, assim como qualquer DLL; aplicativos vincular a ele, assim como qualquer outra DLL.  
  
 As bibliotecas de vínculo estático do MFC padrão são nomeadas de acordo com a convenção descrita no [convenções de nomenclatura para DLLs MFC](../mfc/mfc-library-versions.md#mfc-static-library-naming-conventions). No entanto, com MFC versão 3.0 e posterior, não é necessário especificar manualmente para o vinculador a versão da biblioteca MFC que deseja vincular em. Em vez disso, os arquivos de cabeçalho MFC determinam automaticamente a versão correta da biblioteca MFC para link no pré-processador com base em define, como  **\_depurar** ou **Unicode**. Os arquivos de cabeçalho MFC adicionar diretivas /DEFAULTLIB instrui o vinculador para vincular em uma versão específica da biblioteca do MFC.  
  
## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?  
  
-   [Inicializar a DLLs normais do MFC](../build/run-time-library-behavior.md#initializing-regular-dlls)  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [Usando MFC como parte de uma DLL](../mfc/tn011-using-mfc-as-part-of-a-dll.md)  
  
-   [Usando banco de dados, OLE e DLLs de extensão de MFC de soquetes em DLLs MFC regulares](../build/using-database-ole-and-sockets-extension-dlls-in-regular-dlls.md)  
  
-   [Criar uma DLL MFC](../mfc/reference/mfc-dll-wizard.md)  
  
-   [DLLs MFC regulares vinculadas dinamicamente ao MFC](../build/regular-dlls-dynamically-linked-to-mfc.md)  
  
-   [DLLs de extensão de MFC](../build/extension-dlls-overview.md)  
  
## <a name="see-also"></a>Consulte também  
 [Tipos de DLLs](../build/kinds-of-dlls.md)