---
title: Criando um aplicativo de contêiner de documento ativo
ms.date: 11/04/2016
helpviewer_keywords:
- active documents [MFC], containers
- containers [MFC], active document
- active document containers [MFC], creating
- MFC COM, active document containment
- applications [MFC], active document container
ms.assetid: 14e2d022-a6c5-4249-8712-706b0f4433f7
ms.openlocfilehash: 860a8531a96a0671c808dba13523b492026eafe0
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84616347"
---
# <a name="creating-an-active-document-container-application"></a>Criando um aplicativo de contêiner de documento ativo

A maneira mais simples e recomendada de criar um aplicativo de contêiner de documento ativo é criar um aplicativo de contêiner EXE do MFC usando o assistente de aplicativo do MFC e, em seguida, modificar o aplicativo para dar suporte à contenção do documento ativo.

#### <a name="to-create-an-active-document-container-application"></a>Para criar um aplicativo de contêiner de documento ativo

1. No menu **arquivo** , clique em **projeto**no **novo** submenu.

1. No painel esquerdo, clique em **Visual C++** tipo de projeto.

1. Selecione **aplicativo MFC** no painel direito.

1. Nomeie o projeto como *MyProj*, clique em **OK**.

1. Selecione a página de **suporte de documento composto** .

1. Selecione a opção **contêiner** ou **contêiner/servidor completo** .

1. Marque a caixa de seleção **contêiner do documento ativo** .

1. Clique em **Concluir**.

1. Quando o assistente de aplicativo do MFC terminar de gerar o aplicativo, abra os seguintes arquivos usando Gerenciador de Soluções:

   - *MyProjview. cpp*

1. No *MyProjview. cpp*, faça as seguintes alterações:

   - No `CMyProjView::OnPreparePrinting` , substitua o conteúdo da função pelo código a seguir:

     [!code-cpp[NVC_MFCDocView#56](codesnippet/cpp/creating-an-active-document-container-application_1.cpp)]

   `OnPreparePrinting`fornece suporte para impressão. Esse código substitui `DoPreparePrinting` , que é a preparação de impressão padrão.

   A contenção de documento ativo fornece um esquema de impressão aprimorado:

   - Você pode primeiro chamar o documento ativo por meio de sua `IPrint` interface e pedir para ele imprimir. Isso é diferente da contenção de OLE anterior, na qual o contêiner tinha que renderizar uma imagem do item contido no objeto de impressora `CDC` .

   - Se isso falhar, diga ao item contido para imprimir a si mesmo por meio de sua `IOleCommandTarget` interface

   - Se isso falhar, faça sua própria renderização do item.

   As funções de membro estático `COleDocObjectItem::OnPrint` e `COleDocObjectItem::OnPreparePrinting` , conforme implementado no código anterior, lidam com esse esquema de impressão aprimorado.

1. Adicione qualquer implementação de sua própria e compile o aplicativo.

## <a name="see-also"></a>Consulte também

[Contenção de documentos ativos](active-document-containment.md)
