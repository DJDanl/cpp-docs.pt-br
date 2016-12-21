---
title: "DLLs regulares vinculados estaticamente ao MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "DLLs [C++], regular"
  - "DLLs regulares [C++]"
  - "DLLs regulares [C++], estatisticamente vinculadas a MFC"
  - "DLLs estatisticamente vinculadas [C++]"
  - "USRDLLs"
  - "USRDLLs, estatisticamente vinculadas a MFC"
ms.assetid: 2eed531c-726a-4b8a-b936-f721dc00a7fa
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# DLLs regulares vinculados estaticamente ao MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma DLL vinculado ao normal estaticamente MFC é uma DLL que usa o MFC internamente, as funções e exportadas na DLL podem ser chamadas pelos executáveis MFC ou por não MFC.  Descreve como o nome, o tipo de DLL é construído usando a versão estático de biblioteca de vínculo MFC.  As funções são exportadas em geral de uma DLL normal usando a interface c padrão 2.0.  Para obter um exemplo de como escrever, para criar, e usar uma DLL normal, consulte [DLLScreenCap](http://msdn.microsoft.com/pt-br/2171291d-3a50-403b-90a1-d93c2acb4f4a)de exemplo.  
  
 Observe que o termo está USRDLL mais utilizado na documentação do Visual C\+\+.  Uma DLL normal que é vinculado ao estaticamente MFC tem as mesmas características do USRDLL antigo.  
  
 Uma DLL normal, estaticamente vinculado ao MFC, tem os seguintes recursos:  
  
-   O executável de cliente pode ser escritos em qualquer linguagem com suporte para o uso da DLL \(2.0 C, C\+\+, Pascal, Visual Basic, e assim por diante\); não tem que ser um aplicativo MFC.  
  
-   A DLL pode vincular as mesmas bibliotecas de vínculo estáticos MFC usadas por aplicativos.  Não há mais a versão separado das bibliotecas de vínculo estáticos para a DLL.  
  
-   Antes da versão 4,0 MFC, USRDLLs forneceu o mesmo tipo de funcionalidade das dlls normais vinculados estaticamente MFC ao.  A partir da versão 4,0 do Visual C\+\+, o termo USRDLL é obsoleto.  
  
 Uma DLL normal, estaticamente vinculado ao MFC, tem os seguintes requisitos:  
  
-   Esse tipo de DLL deve criar uma instância de uma classe derivada de `CWinApp`.  
  
-   Esse tipo de DLL usa `DllMain` MFC fornecido pelo.  Coloque todo o código de inicialização DLL\- específico na função de membro de `InitInstance` e o código de término em `ExitInstance` como em um aplicativo MFC normal.  
  
-   Mesmo que o termo USRDLL é obsoleto, você ainda deverá definir “**\_USRDLL**” na linha de comando do compilador.  Esta definição determina quais instruções são recebidas nos arquivos de cabeçalho MFC.  
  
 Dlls normais devem ter `CWinApp`\- classe derivada e um único objeto dessa classe do aplicativo, como faz um aplicativo MFC.  No entanto, o objeto de `CWinApp` da DLL não tiver uma bomba principal da mensagem, como faz o objeto de `CWinApp` de um aplicativo.  
  
 Observe que o mecanismo de `CWinApp::Run` não se aplica a uma DLL, porque o aplicativo possuir a bomba principal da mensagem.  Se a DLL abre caixas de diálogo modeless ou tem uma janela principal do quadro de sua escolha, a bomba principal da mensagem de aplicativo deve chamar uma rotina exportada pela DLL que por sua vez a função de membro de `CWinApp::PreTranslateMessage` do objeto de aplicativo da DLL.  
  
 Para obter um exemplo dessa função, consulte o exemplo de DLLScreenCap.  
  
 Os símbolos são exportados em geral de uma DLL normal usando a interface c padrão 2.0.  A declaração de uma função exportada de uma DLL normal seria algo como:  
  
```  
extern "C" __declspec(dllexport) MyExportedFunction( );  
```  
  
 Todas as alocações de memória dentro de uma DLL normal devem ficar dentro da DLL; a DLL não deve passar a receber ou do executável de chamada dos seguintes:  
  
-   Ponteiros para os objetos MFC  
  
-   Ponteiros à memória alocada por MFC  
  
 Se você precisar fazer alguma de acima ou da necessidade de transmissão de objetos MFC\- derivadas entre o executável de chamada e a DLL, você deve criar uma DLL da extensão.  
  
 É seguro passar os ponteiros à memória que foram atribuídos por bibliotecas de tempo de execução C entre um aplicativo e uma DLL somente se você faz uma cópia dos dados.  Você não precisa redimensionar ou excluir esses ponteiros ou usá\-los sem fazer uma cópia da memória.  
  
 UMA DLL que seja vinculado estaticamente MFC ao também não pode vincular dinamicamente a DLL compartilhados MFC.  UMA DLL que é vinculado ao estaticamente MFC é associado dinamicamente a um aplicativo assim como qualquer outro DLL; link de aplicativos a ele apenas como qualquer outro DLL.  
  
 As bibliotecas de vínculo estáticos MFC de padrão são nomeadas de acordo com a convenção descrita em [Convenções de nomenclatura para dlls MFC](../build/naming-conventions-for-mfc-dlls.md).  No entanto, com MFC versão 3,0 e posteriores, não é mais necessário especificar manualmente para o vinculador a versão da biblioteca MFC que você deseja vinculado em.  Em vez disso, os arquivos de cabeçalho MFC determinar automaticamente a versão correta da biblioteca MFC vincular com base em pré\-processador definem, como **\_DEBUG** ou **\_UNICODE**.  Os arquivos de cabeçalho MFC adicionam as políticas de \/DEFAULTLIB que instruem o vinculador o link em uma versão específica de biblioteca MFC.  
  
## O que você deseja fazer?  
  
-   [Inicializar DLL normais](../Topic/Initializing%20Regular%20DLLs.md)  
  
## Que você deseja saber mais?  
  
-   [Usando o MFC como parte de uma DLL](../mfc/tn011-using-mfc-as-part-of-a-dll.md)  
  
-   [Usando o base de dados, o OLE, e as dlls de extensão de soquetes na DLL normais](../build/using-database-ole-and-sockets-extension-dlls-in-regular-dlls.md)  
  
-   [Criar uma DLL MFC](../mfc/reference/mfc-dll-wizard.md)  
  
-   [DLL normais vinculados dinamicamente ao MFC](../Topic/Regular%20DLLs%20Dynamically%20Linked%20to%20MFC.md)  
  
-   [DLLs de Extensão](../build/extension-dlls-overview.md)  
  
## Consulte também  
 [Tipos de DLLs](../build/kinds-of-dlls.md)