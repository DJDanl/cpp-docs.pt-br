---
title: Estrutura DEVNAMES | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- DEVNAMES
dev_langs:
- C++
helpviewer_keywords:
- DEVNAMES [MFC]
ms.assetid: aac97f60-2169-471a-ba5d-c0baed9eed9a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d91a44a38d331a49927d5129c5002eef53c224ad
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50077966"
---
# <a name="devnames-structure"></a>Estrutura DEVNAMES

O `DEVNAMES` estrutura contém cadeias de caracteres que identificam o driver, dispositivo e nomes de porta de saída para uma impressora.

## <a name="syntax"></a>Sintaxe

```
typedef struct tagDEVNAMES { /* dvnm */
    WORD wDriverOffset;
    WORD wDeviceOffset;
    WORD wOutputOffset;
    WORD wDefault; */* driver,
    device,
    and port-name strings follow wDefault */
} DEVNAMES;
```

#### <a name="parameters"></a>Parâmetros

*wDriverOffset*<br/>
(Entrada/saída) Especifica o deslocamento em caracteres para uma cadeia de caracteres terminada em nulo que contém o nome do arquivo (sem extensão) do driver de dispositivo. Na entrada, essa cadeia de caracteres é usada para determinar a impressora a ser exibido inicialmente na caixa de diálogo.

*wDeviceOffset*<br/>
(Entrada/saída) Especifica o deslocamento em caracteres para a cadeia terminada em nulo (máximo de 32 bytes, incluindo o nulo) que contém o nome do dispositivo. Essa cadeia de caracteres deve ser idêntica para o `dmDeviceName` membro do [DEVMODE](/windows/desktop/api/wingdi/ns-wingdi-_devicemodea) estrutura.

*wOutputOffset*<br/>
(Entrada/saída) Especifica o deslocamento em caracteres para a cadeia de caracteres terminada em nulo que contém o nome do dispositivo para a mídia de saída físico (porta de saída).

*wDefault*<br/>
Especifica se as cadeias de caracteres contida no `DEVNAMES` estrutura identificam a impressora padrão. Essa cadeia de caracteres é usada para verificar se a impressora padrão não foi alterada desde a última operação de impressa. Na entrada, se o sinalizador DN_DEFAULTPRN for definido, os outros valores no `DEVNAMES` estrutura são verificados em relação a impressora padrão atual. Se qualquer uma das cadeias de caracteres não corresponderem, será exibida uma mensagem de aviso informando ao usuário que o documento talvez precise ser reformatado. Na saída, o `wDefault` membro é alterado apenas se a caixa de diálogo Configurar impressão foi exibida e o usuário escolheu o botão Okey. O sinalizador DN_DEFAULTPRN será definido se a impressora padrão foi selecionada. Se uma impressora específica for selecionada, o sinalizador não está definido. Todos os outros bits nesse membro são reservados para uso interno pelo procedimento de caixa de diálogo Imprimir.

## <a name="remarks"></a>Comentários

O `PrintDlg` função utiliza essas cadeias de caracteres para inicializar os membros na caixa de diálogo de impressão definida pelo sistema. Quando o usuário fecha a caixa de diálogo, serão retornadas informações sobre a impressora selecionada nessa estrutura.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** commdlg.h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[CPrintDialog::CreatePrinterDC](../../mfc/reference/cprintdialog-class.md#createprinterdc)

