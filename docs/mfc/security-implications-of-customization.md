---
title: Implicações de segurança da personalização
ms.date: 11/04/2016
helpviewer_keywords:
- security, MFC Feature Pack
- MFC Feature Pack, security
ms.assetid: 9be96b12-be38-43bd-a133-5d671265f7a1
ms.openlocfilehash: 9164983a6634e069195f3498bea56b595a2a2381
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62308466"
---
# <a name="security-implications-of-customization"></a>Implicações de segurança da personalização

Este tópico discute uma potencial vulnerabilidade de segurança no MFC.

## <a name="potential-security-weakness"></a>Falha de segurança potencial

MFC permite que o usuário personalize a aparência de uma interface de usuário do aplicativo, por exemplo, a aparência de botões e ícones. MFC também oferece suporte a ferramentas definidas pelo usuário, que permitem ao usuário executar comandos do shell. Uma vulnerabilidade de segurança surge porque as configurações personalizadas do aplicativo são salvos no perfil do usuário no registro. Qualquer pessoa que pode acessar o registro pode editar essas configurações e alterar a aparência do aplicativo ou o comportamento. Por exemplo, um administrador no computador poderia representar um usuário, fazendo com que o aplicativo do usuário executar programas arbitrários (até mesmo de um compartilhamento de rede).

## <a name="workarounds"></a>Soluções alternativas

É recomendável que qualquer uma destas três maneiras para fechar as vulnerabilidades no registro:

- Criptografar os dados armazenados ali

- Store os dados em um arquivo seguro em vez de no registro.

   Para realizar qualquer uma das maneiras duas primeiras, derive uma classe de [classe CSettingsStore](../mfc/reference/csettingsstore-class.md) e substituir seus métodos para implementar a criptografia ou armazenamento fora do registro.

- Você também pode desabilitar as personalizações em seu aplicativo.

## <a name="see-also"></a>Consulte também

[Personalização para MFC](../mfc/customization-for-mfc.md)
