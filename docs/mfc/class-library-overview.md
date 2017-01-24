---
title: "Vis&#227;o geral da biblioteca de classes | Microsoft Docs"
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
  - "vc.classes.mfc"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "bibliotecas de classes"
  - "bibliotecas de classes, MFC"
  - "classes [C++], MFC"
  - "agrupando classes MFC"
  - "MFC, biblioteca de classes"
ms.assetid: 9b0e3152-ac39-4f52-91b4-f20aa3a674aa
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Vis&#227;o geral da biblioteca de classes
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Essa visão geral categoriza e descreve as classes da Biblioteca de Classes do Microsoft Foundation \(MFC\) versão 9.0.  As classes no MFC, vistas em conjunto, constituem uma estrutura do aplicativo — a estrutura de um aplicativo escrito para a API do Windows.  A tarefa de programação é preencher o código específico para seu aplicativo.  
  
 As classes de biblioteca são apresentadas aqui nas seguintes categorias:  
  
-   [Classe raiz: CObject](../mfc/root-class-cobject.md)  
  
-   [Classes de arquitetura do aplicativo do MFC](../mfc/mfc-application-architecture-classes.md)  
  
    -   [Classes de suporte do aplicativo e de thread](../Topic/Application%20and%20Thread%20Support%20Classes.md)  
  
    -   [Classes de Roteamento de Comando](../mfc/command-routing-classes.md)  
  
    -   [Classes de documento](../mfc/document-classes.md)  
  
    -   [Exibir classes \(arquitetura\)](../mfc/view-classes-architecture.md)  
  
    -   [Classes de janela do quadro \(arquitetura\)](../mfc/frame-window-classes-architecture.md)  
  
    -   [Classes de documento\-modelo](../Topic/Document-Template%20Classes.md)  
  
-   [Classes de controle, de janela e de caixa de diálogo](../mfc/window-dialog-and-control-classes.md)  
  
    -   [Classes de janela do quadro \(Windows\)](../mfc/frame-window-classes-windows.md)  
  
    -   [Exibir classes \(Windows\)](../mfc/view-classes-windows.md)  
  
    -   [Classes de caixa de diálogo](../mfc/dialog-box-classes.md)  
  
    -   [Classes de Controle](../mfc/control-classes.md)  
  
    -   [Classes da Barra de Controle](../mfc/control-bar-classes.md)  
  
-   [Classes de desenho e impressão](../mfc/drawing-and-printing-classes.md)  
  
    -   [Classes de saída \(contexto de dispositivo\)](../Topic/Output%20\(Device%20Context\)%20Classes.md)  
  
    -   [Classes de ferramentas de desenho](../mfc/drawing-tool-classes.md)  
  
-   [Classes de tipo de dados simples](../mfc/simple-data-type-classes.md)  
  
-   [Matriz, lista e classes de mapa](../mfc/array-list-and-map-classes.md)  
  
    -   [Classes de modelo para matrizes, listas e mapas](../mfc/template-classes-for-arrays-lists-and-maps.md)  
  
    -   [Classes de matriz prontas para uso](../Topic/Ready-to-Use%20Array%20Classes.md)  
  
    -   [Classes de lista prontas para uso](../Topic/Ready-to-Use%20List%20Classes.md)  
  
    -   [Classes de mapa prontas para uso](../mfc/ready-to-use-map-classes.md)  
  
-   [Classes de banco de dados e arquivo](../mfc/file-and-database-classes.md)  
  
    -   [Classes de E\/S de arquivo](../Topic/File%20I-O%20Classes.md)  
  
    -   [Classes DAO](../mfc/dao-classes.md)  
  
    -   [Classes ODBC](../Topic/ODBC%20Classes.md)  
  
    -   [Classes OLE DB](../mfc/ole-db-classes.md)  
  
-   [A Internet e Classes de Acesso à Rede](../mfc/internet-and-networking-classes.md)  
  
    -   [Classes de soquetes do Windows](../mfc/windows-sockets-classes.md)  
  
    -   [Classes de Internet Win32](../mfc/win32-internet-classes.md)  
  
-   [Classes OLE](../mfc/ole-classes.md)  
  
    -   [Classe de contêiner OLE](../mfc/ole-container-classes.md)  
  
    -   [Classes de Servidor OLE](../mfc/ole-server-classes.md)  
  
    -   [Arrastar e soltar OLE e Classes de Transferência de Dados](../mfc/ole-drag-and-drop-and-data-transfer-classes.md)  
  
    -   [Classes de Diálogo Comuns OLE](../mfc/ole-common-dialog-classes.md)  
  
    -   [Classes de Automação OLE](../Topic/OLE%20Automation%20Classes.md)  
  
    -   [Classes de controle OLE](../mfc/ole-control-classes.md)  
  
    -   [Classes de Documento Ativas](../mfc/active-document-classes.md)  
  
    -   [Classes Relacionadas a OLE](../mfc/ole-related-classes.md)  
  
-   [Classes de depuração e exceção](../Topic/Debugging%20and%20Exception%20Classes.md)  
  
    -   [Depurando classes de suporte](../mfc/debugging-support-classes.md)  
  
    -   [Classes de exceção](../mfc/exception-classes.md)  
  
 A seção [Filosofia de design de classe geral](../mfc/general-class-design-philosophy.md) explica como a biblioteca do MFC foi projetada.  
  
 Para obter uma visão geral da estrutura, consulte [Usando as classes para gravar aplicativos para o Windows](../Topic/Using%20the%20Classes%20to%20Write%20Applications%20for%20Windows.md).  Algumas das classes listadas acima são classes de finalidade geral que podem ser usadas fora da estrutura e oferecem abstrações úteis, como coleções, exceções, arquivos e cadeias de caracteres.  
  
 Para ver a herança de uma classe, use o [Gráfico da hierarquia de classe](../mfc/hierarchy-chart.md).  
  
 Além das classes listadas nesta visão geral, a biblioteca do MFC contém várias funções globais, variáveis globais e macros.  Há uma visão geral e uma listagem detalhada deles no tópico [Macros e globals do MFC](../mfc/reference/mfc-macros-and-globals.md), que segue a referência alfabética das classes do MFC.  
  
## Consulte também  
 [Aplicativos para desktop do MFC](../mfc/mfc-desktop-applications.md)