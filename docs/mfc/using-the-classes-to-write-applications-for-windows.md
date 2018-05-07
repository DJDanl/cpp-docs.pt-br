---
title: Usando as Classes para escrever aplicativos para Windows | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Windows applications [MFC], MFC application framework
- MFC, application development
- applications [OLE], MFC application framework
- MFC ActiveX controls [MFC], creating
- OLE applications [MFC], MFC application framework
- database applications [MFC], creating
ms.assetid: 73f63470-857d-43dd-9a54-b38b7be0f1b7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fa126f2772e1672a1484453fdffdd487b6c45959
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="using-the-classes-to-write-applications-for-windows"></a>Usando as classes para escrever aplicativos para Windows
As classes da biblioteca Microsoft Foundation Class (MFC) juntos, compõem uma "estrutura de aplicativo", em que você criar um aplicativo para o sistema operacional Windows. Em um nível muito geral, a estrutura define o esqueleto de um aplicativo e fornece implementações de interface do usuário padrão que podem ser colocadas no esqueleto. Seu trabalho como programador é preencha o restante do esqueleto, que são as coisas que são específicas para seu aplicativo. Você pode obter uma vantagem inicial usando o Assistente de aplicativo MFC para criar os arquivos para um aplicativo de início bem completo. Você pode usar os Microsoft Visual C++ editores de recursos para criar os elementos de interface do usuário visualmente, os comandos de exibição de classe para se conectar a esses elementos de código e a biblioteca de classes para implementar a lógica específica do aplicativo.  
  
 Dá suporte a versão 3.0 e posterior do framework MFC de programação para plataformas Win32, incluindo o Microsoft Windows 95 e posterior e as versões do Windows NT 3.51 e posteriores. Suporte a MFC Win32 inclui multithreading. Versão 1.5 do uso*x* se você precisar fazer programação de 16 bits.  
  
 Essa família de artigos apresenta uma visão geral da estrutura do aplicativo. Ele também explora os principais objetos que compõem seu aplicativo e como eles são criados. Entre os tópicos abordados neste artigo são os seguintes:  
  
-   [A estrutura](../mfc/framework-mfc.md).  
  
-   Divisão de trabalho entre a estrutura e seu código, conforme descrito em [Compilando no Framework](../mfc/building-on-the-framework.md).  
  
-   [A classe do aplicativo](../mfc/cwinapp-the-application-class.md), que encapsula a funcionalidade de nível de aplicativo.  
  
-   Como [modelos de documento](../mfc/document-templates-and-the-document-view-creation-process.md) criar e gerenciar documentos e seus modos de exibição associados e janelas com moldura.  
  
-   Classe [CWnd](../mfc/window-objects.md), a classe base da raiz de todas as janelas.  
  
-   [Objetos gráficos](../mfc/graphic-objects.md), como pincéis e canetas.  
  
 Outras partes do framework incluem:  
  
-   [Objetos de janela: Visão geral](../mfc/window-objects.md)  
  
-   [Mapeamento e a manipulação de mensagens](../mfc/message-handling-and-mapping.md)  
  
-   [CObject, a classe Base raiz em MFC](../mfc/using-cobject.md)  
  
-   [Arquitetura de documento/exibição](../mfc/document-view-architecture.md)  
  
-   [Caixas de diálogo](../mfc/dialog-boxes.md)  
  
-   [Controles](../mfc/controls-mfc.md)  
  
-   [Barras de controle](../mfc/control-bars.md)  
  
-   [OLE](../mfc/ole-in-mfc.md)  
  
-   [Gerenciamento de memória](../mfc/memory-management.md)  
  
     Além de fornecer uma vantagem ao escrever aplicativos para o sistema operacional Windows, MFC também torna muito mais fácil escrever aplicativos que usam especificamente OLE vinculando e inserindo tecnologia. Você pode tornar seu aplicativo uma OLE visual de edição de contêiner, um servidor de edição visual OLE ou ambos, e você pode adicionar a automação para que outros aplicativos possam usar objetos do seu aplicativo ou até mesmo a unidade remotamente.  
  
-   [Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)  
  
     O kit de desenvolvimento de controle OLE (CDK) agora está totalmente integrado com o framework. Família este artigo fornece uma visão geral do desenvolvimento de controle ActiveX com MFC. (Controles ActiveX eram anteriormente conhecidos como controles OLE.)  
  
-   [Programação de banco de dados](../data/data-access-programming-mfc-atl.md)  
  
     MFC também fornece dois conjuntos de classes de banco de dados que simplificam o acesso a dados gravação de aplicativos. Usando as classes de banco de dados ODBC, você pode se conectar aos bancos de dados por meio de um driver de conectividade de banco de dados aberto (ODBC), selecione registros das tabelas e exibir informações de registro em um formulário na tela. Usando as classes de objeto de acesso a dados (DAO), você pode trabalhar com bancos de dados por meio do mecanismo de banco de dados Microsoft Jet ou fontes de dados (não Jet) externa, incluindo fontes de dados ODBC.  
  
     Além disso, MFC está totalmente habilitado para escrever aplicativos que usam o Unicode e conjuntos de caracteres de multibyte (MBCS), conjuntos de caracteres de byte duplo especificamente (DBCS).  
  
 Para obter um guia geral para a documentação do MFC, consulte [tópicos MFC gerais](../mfc/general-mfc-topics.md).  
  
## <a name="see-also"></a>Consulte também  
 [Tópicos gerais do MFC](../mfc/general-mfc-topics.md)

