---
title: /ERRORREPORT (dumpbin.exe)
description: Referência para a opção de linha de comando/ERRORREPORT do utilitário DUMPBIN da Microsoft.
ms.date: 02/09/2020
f1_keywords:
- /ERRORREPORT_dumpbin
helpviewer_keywords:
- -ERRORREPORT dumpbin option
- ERRORREPORT dumpbin option
- /ERRORREPORT dumpbin option
ms.assetid: 51178c43-4f95-4fda-8f97-50a257d1c948
ms.openlocfilehash: f701c2e28dcf82194589877709bf6959de4bcbfc
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79439940"
---
# <a name="errorreport-dumpbinexe"></a>/ERRORREPORT (dumpbin.exe)

> [!NOTE]
> A opção/ERRORREPORT é preterida. A partir do Windows Vista, o relatório de erros é controlado pelas configurações [do relatório de erros do Windows (WER)](/windows/win32/wer/windows-error-reporting) .

## <a name="syntax"></a>Sintaxe

> **/Errorreport**\[**None** \| **prompt** de \| **fila** \| **Enviar** )

## <a name="remarks"></a>Comentários

Os argumentos **/errorreport** são substituídos pelas configurações do serviço relatório de erros do Windows. O DUMPBIN envia automaticamente relatórios de erros internos à Microsoft, se os relatórios estiverem habilitados pelo Relatório de Erros do Windows. Nenhum relatório será enviado se for desabilitado pelo Relatório de Erros do Windows.

## <a name="see-also"></a>Consulte também

[Opções de DUMPBIN](dumpbin-options.md)
