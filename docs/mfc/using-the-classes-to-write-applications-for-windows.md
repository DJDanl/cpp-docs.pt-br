---
title: Usando as classes para escrever aplicativos para Windows
ms.date: 11/04/2016
helpviewer_keywords:
- Windows applications [MFC], MFC application framework
- MFC, application development
- applications [OLE], MFC application framework
- MFC ActiveX controls [MFC], creating
- OLE applications [MFC], MFC application framework
- database applications [MFC], creating
ms.assetid: 73f63470-857d-43dd-9a54-b38b7be0f1b7
ms.openlocfilehash: eaa1c178a8d93315d5477efa1213ed0698cd460c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50517319"
---
# <a name="using-the-classes-to-write-applications-for-windows"></a>Usando as classes para escrever aplicativos para Windows

As classes na biblioteca Microsoft Foundation Class (MFC) juntos, compõem uma "estrutura de aplicativo", na qual você criar um aplicativo para o sistema operacional Windows. Em um nível muito geral, a estrutura define o esqueleto de um aplicativo e fornece implementações de interface do usuário padrão que podem ser colocadas no esqueleto. Seu trabalho como programador é preencher o restante de esqueleto, que são essas coisas que são específicas para seu aplicativo. Você pode obter uma vantagem inicial usando o Assistente de aplicativo do MFC para criar os arquivos para um aplicativo bem completo starter. Você pode usar os Microsoft Visual C++ editores de recursos para criar os elementos de interface do usuário visualmente, comandos do modo de exibição de classe para se conectar a esses elementos de código e a biblioteca de classes para implementar a lógica específica ao aplicativo.

Versão 3.0 e posterior da estrutura MFC dá suporte à programação para plataformas Win32, incluindo o Microsoft Windows 95 e posterior e o Windows NT versões 3.51 e posterior. Suporte ao MFC Win32 inclui multithreading. Use a versão 1.5*x* se você precisar fazer programação de 16 bits.

Essa família de artigos apresenta uma visão geral da estrutura de aplicativo. Ele também explora os principais objetos que compõem seu aplicativo e como eles são criados. Entre os tópicos abordados nesses artigos são os seguintes:

- [A estrutura](../mfc/framework-mfc.md).

- Divisão de trabalho entre a estrutura e seu código, conforme descrito em [Compilando no Framework](../mfc/building-on-the-framework.md).

- [A classe do aplicativo](../mfc/cwinapp-the-application-class.md), que encapsula a funcionalidade de nível de aplicativo.

- Como [modelos de documento](../mfc/document-templates-and-the-document-view-creation-process.md) criar e gerenciar documentos e suas exibições associadas e janelas com moldura.

- Classe [CWnd](../mfc/window-objects.md), a classe base da raiz de todas as janelas.

- [Objetos gráficos](../mfc/graphic-objects.md), como canetas e pincéis.

Outras partes do framework incluem:

- [Objetos de janela: Visão geral](../mfc/window-objects.md)

- [Mapeamento e manipulação de mensagens](../mfc/message-handling-and-mapping.md)

- [CObject, a classe Base da raiz no MFC](../mfc/using-cobject.md)

- [Arquitetura de documento/exibição](../mfc/document-view-architecture.md)

- [Caixas de diálogo](../mfc/dialog-boxes.md)

- [Controles](../mfc/controls-mfc.md)

- [Barras de controle](../mfc/control-bars.md)

- [OLE](../mfc/ole-in-mfc.md)

- [Gerenciamento de memória](../mfc/memory-management.md)

   Além de fornecer uma vantagem em escrever aplicativos para o sistema operacional Windows, MFC também torna muito mais fácil escrever aplicativos que usam especificamente OLE vinculação e incorporação de tecnologia. Você pode tornar seu aplicativo uma OLE visual de edição de contêiner, um servidor de edição visual OLE ou ambos, e você pode adicionar automação para que outros aplicativos possam usar objetos do seu aplicativo ou até mesmo conduzi-lo remotamente.

- [Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)

   O kit de desenvolvimento de controle OLE (CDK) agora está totalmente integrado com o framework. Família este artigo fornece uma visão geral do desenvolvimento de controles ActiveX com o MFC. (Controles ActiveX eram anteriormente conhecidos como controles OLE.)

- [Programação de banco de dados](../data/data-access-programming-mfc-atl.md)

   MFC também fornece dois conjuntos de classes de banco de dados que simplificam o acesso a dados de gravação de aplicativos. Usando as classes de banco de dados ODBC, você pode se conectar aos bancos de dados por meio de um driver ODBC Open Database Connectivity (), selecione registros nas tabelas e exibir informações do registro em um formulário na tela. Usando as classes de objeto de acesso de dados (DAO), você pode trabalhar com bancos de dados por meio do mecanismo de banco de dados Microsoft Jet ou fontes de dados de (não-Jet) externos, incluindo fontes de dados ODBC.

   Além disso, MFC está totalmente habilitado para escrever aplicativos que usam o Unicode e conjuntos de caracteres multibyte (MBCS), conjuntos de caracteres de byte duplo especificamente (DBCS).

Para obter um guia geral para a documentação do MFC, consulte [tópicos MFC gerais](../mfc/general-mfc-topics.md).

## <a name="see-also"></a>Consulte também

[Tópicos gerais do MFC](../mfc/general-mfc-topics.md)

