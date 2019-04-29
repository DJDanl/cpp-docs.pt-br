---
title: Erro PRJ0016 (compilação de projeto)
ms.date: 11/04/2016
f1_keywords:
- PRJ0016
helpviewer_keywords:
- PRJ0016
ms.assetid: e9745336-883a-4c70-9c40-7753e02f0325
ms.openlocfilehash: ada89b074fd8e0c2bfc75ba833e9c5966a145312
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62359417"
---
# <a name="project-build-error-prj0016"></a>Erro PRJ0016 (compilação de projeto)

Configurações de segurança do usuário evitam que o processo que está sendo criado. Essas configurações são necessárias para a compilação.

Você está conectado como um usuário que não tem permissões para criar processos usando um processo. Você deve alterar os níveis de permissão para esta conta de usuário ou entre em contato com seu administrador da conta.

Esse erro também pode ocorrer se a seguinte chave do registro é definida:

\\\HKCU\Software\Microsoft\Windows\CurrentVersion\Policies\Explorer\RestrictRun

Para resolver esse erro, exclua a chave de RestrictRun. Se essa chave do registro é necessário, acrescente **vcspawn.exe** à lista de entradas na chave.

Outra causa desse erro é que sua configuração de política não inclui VCSpawn.exe sob a chave do registro HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Policies\RestrictRun como um programa de janela permitido para esta conta de usuário.

Para obter mais informações, consulte [aderindo às configurações de política do sistema](https://msdn.microsoft.com/library/aa372139), na seção "Executar apenas aplicativos do Windows permitidos".