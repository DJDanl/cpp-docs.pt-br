---
title: Segurança da Internet (C++)
ms.date: 11/04/2016
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
ms.openlocfilehash: ce044014c5c2e13528cea8b982227b0ec8bc03fc
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84621533"
---
# <a name="internet-security-c"></a>Segurança da Internet (C++)

A segurança de código é um problema importante para desenvolvedores e usuários de aplicativos da Internet. Há riscos: código mal-intencionado, código que foi adulterado e código de sites ou autores desconhecidos.

Há duas abordagens básicas para a segurança ao desenvolver para a Internet. A primeira é chamada de "sandbox". Nessa abordagem, um aplicativo é restrito a um conjunto específico de APIs e excluído de potencialmente perigoso, como e/s de arquivo, em que um programa pode destruir dados no computador de um usuário. O segundo é implementado usando assinaturas digitais. Essa abordagem é conhecida como "shrinkwrap" para a Internet. O código é verificado e assinado usando a tecnologia de chave privada/chave pública. Antes da execução do código, sua assinatura digital é verificada para garantir que o código seja de uma fonte autenticada conhecida e que o código não tenha sido alterado desde que tenha sido assinado.

No primeiro caso, você confia que o aplicativo não fará nenhum dano e você confia na origem do aplicativo. No segundo, as assinaturas digitais são usadas para verificar a autenticidade. A assinatura digital é um padrão do setor usado para identificar e fornecer detalhes sobre o editor do código. Sua tecnologia se baseia em padrões, incluindo RSA e X. 509. Os navegadores normalmente permitem que os usuários escolham se desejam baixar e executar código de origem desconhecida.

## <a name="see-also"></a>Consulte também

[Tarefas de programação da Internet no MFC](mfc-internet-programming-tasks.md)<br/>
[Noções básicas de programação na Internet do MFC](mfc-internet-programming-basics.md)
