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
ms.openlocfilehash: ecce997c451b39600606550dd1198cddfd764334
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50463319"
---
# <a name="creating-an-active-document-container-application"></a>Criando um aplicativo de contêiner de documento ativo

A maneira mais simples e mais recomendada para criar um aplicativo de contêiner do documento ativo é criar um aplicativo de contêiner do MFC EXE usando o Assistente de aplicativo do MFC, em seguida, modificar o aplicativo para dar suporte a contenção de documento ativo.

#### <a name="to-create-an-active-document-container-application"></a>Para criar um aplicativo de contêiner do documento ativo

1. Do **arquivo** menu, clique em **Project**do **New** submenu.

1. No painel esquerdo, clique em **Visual C++** tipo de projeto.

1. Selecione **aplicativo do MFC** no painel à direita.

1. Nomeie o projeto *MeuProjeto*, clique em **Okey**.

1. Selecione o **suporte de documento composto** página.

1. Selecione o **recipiente** ou **contêiner/servidor completo** opção.

1. Selecione o **contêiner de documento ativo** caixa de seleção.

1. Clique em **Finalizar**.

9. Quando o Assistente de aplicativo do MFC terminar de gerar o aplicativo, abra os arquivos a seguir usando o Gerenciador de soluções:

   - *MyProjview.cpp*

10. Na *MyProjview.cpp*, faça as seguintes alterações:

   - No `CMyProjView::OnPreparePrinting`, substitua o conteúdo de função com o código a seguir:

         [!code-cpp[NVC_MFCDocView#56](../mfc/codesnippet/cpp/creating-an-active-document-container-application_1.cpp)]

   `OnPreparePrinting` fornece suporte para impressão. Esse código substitui `DoPreparePrinting`, que é a preparação de impressão padrão.

   Contenção de documento ativa fornece um esquema de impressão aprimorado:

   - Primeiro, você pode chamar o documento ativo por meio de seu `IPrint` de interface e informar a ele para imprimir em si. Isso é diferente do anterior confinamento OLE, no qual o contêiner tinha que processar uma imagem do item contido na impressora `CDC` objeto.

   - Se isso falhar, informar ao item independente para imprimir em si por meio de seu `IOleCommandTarget` interface

   - Se isso falhar, verifique sua própria renderização do item.

   As funções de membro estático `COleDocObjectItem::OnPrint` e `COleDocObjectItem::OnPreparePrinting`, conforme implementado no código anterior, lidar com esse esquema de impressão aprimorada.

11. Adicione qualquer implementação de sua preferência e compile o aplicativo.

## <a name="see-also"></a>Consulte também

[Contenção de documentos ativos](../mfc/active-document-containment.md)

