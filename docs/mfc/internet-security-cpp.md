---
title: "Segurança da Internet (C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
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
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1a44e528e871d784c432730799c44ac91af465be
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="internet-security-c"></a>Segurança da Internet (C++)
Segurança de código é uma questão importante para os desenvolvedores e usuários de aplicativos da Internet. Há riscos: código mal-intencionado, o código que foi violado e o código de sites desconhecidos ou autores.  
  
 Há duas abordagens básicas de segurança ao desenvolver para a Internet. A primeira é chamada de "área restrita." Nessa abordagem, um aplicativo é restrito a um determinado conjunto de APIs e excluído daquelas potencialmente perigosos como e/s de arquivo em que um programa pode destruir dados no computador do usuário. O segundo é implementado usando assinaturas digitais. Essa abordagem é conhecida como "shrinkwrap" para a Internet. Código é verificado e assinada usando a tecnologia de chave de chave pública/privada. Antes do código é executado, sua assinatura digital é verificada para garantir que o código é de uma fonte autenticada conhecida e que o código não foi alterado desde que foi assinado.  
  
 No primeiro caso, você confia que o aplicativo não fará qualquer problema e confia na origem do aplicativo. No segundo, assinaturas digitais são usadas para verificar a autenticidade. A assinatura digital é um padrão da indústria usada para identificar e fornecer detalhes sobre o Editor do código. Sua tecnologia é baseada em padrões, inclusive RSA e x. 509. Navegadores normalmente permite que os usuários escolham se desejam baixar e executar o código de origem desconhecida.  
  
  
## <a name="see-also"></a>Consulte também  
 [Tarefas de programação da Internet MFC](../mfc/mfc-internet-programming-tasks.md)   
 [Noções básicas de programação da Internet no MFC](../mfc/mfc-internet-programming-basics.md)

