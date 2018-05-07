---
title: Implicações de segurança da personalização | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- security, MFC Feature Pack
- MFC Feature Pack, security
ms.assetid: 9be96b12-be38-43bd-a133-5d671265f7a1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1416a586af479ea7b476a6c85d45992ba18873ef
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="security-implications-of-customization"></a>Implicações de segurança da personalização
Este tópico discute uma potencial vulnerabilidade de segurança no MFC.  
  
## <a name="potential-security-weakness"></a>Vulnerabilidade de segurança potencial  
 MFC permite que o usuário personalize a aparência de uma interface de usuário do aplicativo, por exemplo, a aparência de botões e ícones. MFC também oferece suporte a ferramentas definidas pelo usuário, que permitem que o usuário execute comandos do shell. Uma vulnerabilidade de segurança ocorre porque as configurações personalizadas do aplicativo são salvos no perfil do usuário no registro. Quem pode acessar o registro pode editar essas configurações e alterar a aparência de aplicativo ou o comportamento. Por exemplo, um administrador no computador pode representar um usuário fazendo com que o aplicativo do usuário executar programas arbitrários (até mesmo de um compartilhamento de rede).  
  
## <a name="workarounds"></a>Soluções alternativas  
 Recomendamos que qualquer uma destas três maneiras para fechar as vulnerabilidades no registro:  
  
-   Criptografar os dados armazenados nelas  
  
-   Armazene os dados em um arquivo seguro, em vez de no registro.  
  
     Para realizar qualquer uma das maneiras dois primeiros, derive uma classe de [CSettingsStore classe](../mfc/reference/csettingsstore-class.md) e substituir seus métodos para implementar a criptografia ou armazenamento fora do registro.  
  
-   Você também pode desabilitar as personalizações em seu aplicativo.  
  
## <a name="see-also"></a>Consulte também  
 [Personalização para MFC](../mfc/customization-for-mfc.md)

