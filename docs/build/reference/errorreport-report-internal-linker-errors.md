---
title: /ERRORREPORT (erros de vinculador internos do relatório)
description: Saiba como usar o/ERRORREPORT.
ms.date: 02/09/2020
f1_keywords:
- /ERRORREPORT
- VC.Project.VCLinkerTool.ErrorReporting
helpviewer_keywords:
- /ERRORREPORT linker option
- ERRORREPORT linker option
- -ERRORREPORT linker option
ms.assetid: f5fab595-a2f1-4eb0-ab5c-1c0fbd3d8c28
ms.openlocfilehash: 7d16904da8490018235278347f23e37339739415
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90742730"
---
# <a name="errorreport-report-internal-linker-errors"></a>/ERRORREPORT (erros de vinculador internos do relatório)

A opção **/errorreport** é preterida. A partir do Windows Vista, o relatório de erros é controlado pelas configurações [do relatório de erros do Windows (WER)](/windows/win32/wer/windows-error-reporting) .

## <a name="syntax"></a>Sintaxe

> **/Errorreport:** \[ **nenhum** \| **aviso** \| **fila** \| **Enviar** ]

## <a name="remarks"></a>Comentários

Os argumentos **/errorreport** são substituídos pelas configurações do serviço relatório de erros do Windows. O vinculador envia automaticamente relatórios de erros internos à Microsoft, se os relatórios estiverem habilitados pelo Relatório de Erros do Windows. Nenhum relatório será enviado se for desabilitado pelo Relatório de Erros do Windows.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter mais informações, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Abra a **Configuration Properties**  >  página de propriedade avançada do**vinculador**de propriedades de configuração  >  **Advanced** .

1. Modifique a propriedade **relatório de erros** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.ErrorReporting%2A>.

## <a name="see-also"></a>Confira também

[Referência do vinculador MSVC](linking.md)\
[Opções de vinculador MSVC](linker-options.md)
