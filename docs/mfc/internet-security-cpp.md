---
title: Segurança da Internet (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- code signing [MFC], Internet security
- sandboxing [MFC]
- digital signatures [MFC], Internet security
- code signing [MFC]
- Web application security [MFC]
- code access security [MFC], Internet security considerations
- security [MFC]
- security [MFC], Internet
- Internet applications [MFC], security
- Web application security [MFC], Internet security approaches
ms.assetid: bf0da697-81bc-41f0-83fa-d7f82ed83df8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3b61df9a17903f50ea922edf9c29eee926063254
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50055405"
---
# <a name="internet-security-c"></a>Segurança da Internet (C++)

Código de segurança é uma questão importante para os desenvolvedores e usuários de aplicativos da Internet. Há riscos: código mal-intencionado, o código que foram violado e o código de sites desconhecidos ou autores.

Há duas abordagens básicas de segurança ao desenvolver para a Internet. A primeira é chamada de "área restrita." Nessa abordagem, um aplicativo é restrito a um determinado conjunto de APIs e excluído da mais potencialmente perigosos como e/s de arquivo em que um programa pode destruir dados em um computador do usuário. A segunda é implementada usando assinaturas digitais. Essa abordagem é conhecida como "shrinkwrap" para a Internet. Código é verificado e assinada usando a tecnologia de chave de chave pública/privada. Antes do código é executado, sua assinatura digital é verificada para garantir que o código é de uma origem autenticada conhecida e que o código não tenha sido alterado desde que foi assinado.

No primeiro caso, você confia que o aplicativo não fará nenhum dano e confia na origem do aplicativo. Na segunda, assinaturas digitais são usadas para verificar autenticidade. A assinatura digital é um padrão da indústria usado para identificar e fornecer detalhes sobre o Editor do código. Sua tecnologia baseia-se em padrões, incluindo a RSA e x. 509. Navegadores normalmente permite que os usuários escolham se desejam baixar e executar o código de origem desconhecida.

## <a name="see-also"></a>Consulte também

[Tarefas de programação da Internet no MFC](../mfc/mfc-internet-programming-tasks.md)<br/>
[Noções básicas de programação da Internet no MFC](../mfc/mfc-internet-programming-basics.md)

