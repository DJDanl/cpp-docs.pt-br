---
title: Erro PRJ0016 (compilação de projeto)
ms.date: 11/04/2016
f1_keywords:
- PRJ0016
helpviewer_keywords:
- PRJ0016
ms.assetid: e9745336-883a-4c70-9c40-7753e02f0325
ms.openlocfilehash: 6733ef1f390f2ff377356dda3f7cd3ebfe10cc2b
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69509876"
---
# <a name="project-build-error-prj0016"></a>Erro PRJ0016 (compilação de projeto)

As configurações de segurança do usuário impedem que o processo seja criado. Essas configurações são necessárias para a compilação.

Você está conectado como um usuário que não tem permissões para criar processos usando um processo. Você deve alterar os níveis de permissão para essa conta de usuário ou entrar em contato com o administrador da conta.

Esse erro também pode ocorrer se a seguinte chave do registro estiver definida:

\\\HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\RestrictRun

Para resolver esse erro, exclua a chave RestrictRun. Se essa chave do registro for necessária, acrescente **VCSpawn. exe** à lista de entradas na chave.

Outra causa desse erro é que a configuração de política não inclui VCSpawn. exe na chave do registro HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\RestrictRun como um programa de janela permitido para essa conta de usuário.

Para obter informações adicionais, consulte [aderir às configurações de política do sistema](/previous-versions/windows/desktop/Policy/adhering-to-system-policy-settings), na seção "executar somente aplicativos do Windows permitidos".