---
title: Erro de BSCMAKE BK1503 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- BK1503
dev_langs:
- C++
helpviewer_keywords:
- BK1503
ms.assetid: e6582344-b91e-486f-baf3-4f9028d83c3b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 16bf228804cb24f4fe7a2428dc581116d4cec91d
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46064652"
---
# <a name="bscmake-error-bk1503"></a>Erro BK1503 (BSCMAKE)

não é possível gravar no arquivo 'filename' [: motivo]

BSCMAKE combina arquivos. SBR gerados durante a compilação em um banco de dados do navegador. Se o banco de dados resultante do navegador excede 64 MB, ou se o número de arquivos de entrada (. SBR) excede 4092, esse erro será emitido.

Se o problema é causado por arquivos de mais de 4092. SBR, você deve reduzir o número de arquivos de entrada. De dentro do Visual Studio, isso pode ser feito [/FR](../../build/reference/fr-fr-create-dot-sbr-file.md) seu projeto inteiro, em seguida, verificar novamente em uma base de arquivo por arquivo.

Se o problema é causado por um arquivo. bsc maior que 64MB, reduzindo o número de arquivos. SBR como entrada diminuirá o tamanho do arquivo. bsc resultante. Além disso, a quantidade de informações de pesquisa pode ser reduzida com o uso de /Em (Excluir Macro expandida símbolos), /El (excluir variáveis locais) e /Es (excluir arquivos do sistema).

## <a name="see-also"></a>Consulte também

[Opções de BSCMAKE](../../build/reference/bscmake-options.md)