---
title: Criando um aplicativo de contêiner de documento ativo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- active documents [MFC], containers
- containers [MFC], active document
- active document containers [MFC], creating
- MFC COM, active document containment
- applications [MFC], active document container
ms.assetid: 14e2d022-a6c5-4249-8712-706b0f4433f7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 880c6953addd0ec7db3abf5864010bd472d2d5a3
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="creating-an-active-document-container-application"></a>Criando um aplicativo de contêiner de documento ativo
A maneira mais simples e mais recomendada para criar um aplicativo de contêiner do documento ativo é criar um aplicativo de contêiner EXE do MFC usando o Assistente de aplicativo MFC, em seguida, modificar o aplicativo para oferecer suporte a contenção de documentos ativos.  
  
#### <a name="to-create-an-active-document-container-application"></a>Para criar um aplicativo de contêiner do documento ativo  
  
1.  Do **arquivo** menu, clique em **projeto**do **novo** submenu.  
  
2.  No painel esquerdo, clique em **Visual C++** tipo de projeto.  
  
3.  Selecione **aplicativo MFC** no painel direito.  
  
4.  Nomeie o projeto `MyProj`, clique em **Okey**.  
  
5.  Selecione o **suporte a documentos compostos** página.  
  
6.  Selecione o **contêiner** ou **contêiner/servidor completo** opção.  
  
7.  Selecione o **contêiner de documento ativo** caixa de seleção.  
  
8.  Clique em **Finalizar**.  
  
9. Quando o Assistente de aplicativo MFC terminar de gerar o aplicativo, abra os arquivos a seguir usando o Gerenciador de soluções:  
  
    -   MyProjview.cpp  
  
10. No MyProjview.cpp, faça as seguintes alterações:  
  
    -   Em `CMyProjView::OnPreparePrinting`, substitua o conteúdo de função com o código a seguir:  
  
         [!code-cpp[NVC_MFCDocView#56](../mfc/codesnippet/cpp/creating-an-active-document-container-application_1.cpp)]  
  
     `OnPreparePrinting` fornece suporte de impressão. Esse código substitui `DoPreparePrinting`, que é a preparação de impressão padrão.  
  
     Contenção de documento ativa fornece um esquema melhorado de impressão:  
  
    -   Primeiro, você pode chamar o documento ativo por meio de seu `IPrint` interface e solicita que seja impresso em si. Isso é diferente do anterior contenção OLE, no qual o contêiner precisava processar uma imagem do item contido na impressora `CDC` objeto.  
  
    -   Se isso falhar, informar ao item independente para imprimir a mesmo por meio de seu `IOleCommandTarget` interface  
  
    -   Se isso falhar, verifique o seu próprio processamento do item.  
  
     As funções de membro estático `COleDocObjectItem::OnPrint` e `COleDocObjectItem::OnPreparePrinting`, conforme implementado no código anterior, lidar com esse esquema de impressão aprimorada.  
  
11. Adicione qualquer implementação de sua preferência e compilar o aplicativo.  
  
## <a name="see-also"></a>Consulte também  
 [Contenção de documentos ativos](../mfc/active-document-containment.md)

