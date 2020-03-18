---
title: /ERRORREPORT (editbin.exe)
description: Referência para a opção de linha de comando/ERRORREPORT do utilitário EDITBIN da Microsoft.
ms.date: 02/09/2020
f1_keywords:
- /ERRORREPORT_editbin
helpviewer_keywords:
- -ERRORREPORT editbin option
- ERRORREPORT editbin option
- /ERRORREPORT editbin option
ms.assetid: eca66ac3-b754-4bd7-9dd4-e04fc79a71b6
ms.openlocfilehash: 4456a49cc53b21bd24c616852159ca299181071b
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79439903"
---
# <a name="errorreport-editbinexe"></a>/ERRORREPORT (editbin.exe)

> [!NOTE]
> A opção/ERRORREPORT é preterida. A partir do Windows Vista, o relatório de erros é controlado pelas configurações [do relatório de erros do Windows (WER)](/windows/win32/wer/windows-error-reporting) .

## <a name="syntax"></a>Sintaxe

> **/Errorreport** \[ **None** \| **prompt** de \| **fila** \| **Enviar** )

## <a name="remarks"></a>Comentários

Os argumentos **/errorreport** são substituídos pelas configurações do serviço relatório de erros do Windows. O EDITBIN envia automaticamente relatórios de erros internos à Microsoft, se os relatórios estiverem habilitados pelo Relatório de Erros do Windows. Nenhum relatório será enviado se for desabilitado pelo Relatório de Erros do Windows.

## <a name="see-also"></a>Consulte também

[Opções de EDITBIN](editbin-options.md)
