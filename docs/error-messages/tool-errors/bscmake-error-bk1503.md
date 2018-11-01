---
title: Erro BK1503 (BSCMAKE)
ms.date: 11/04/2016
f1_keywords:
- BK1503
helpviewer_keywords:
- BK1503
ms.assetid: e6582344-b91e-486f-baf3-4f9028d83c3b
ms.openlocfilehash: 2c8ca005922c3c94b557e2f1052e8811099d9948
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50555749"
---
# <a name="bscmake-error-bk1503"></a>Erro BK1503 (BSCMAKE)

não é possível gravar no arquivo 'filename' [: motivo]

BSCMAKE combina arquivos. SBR gerados durante a compilação em um banco de dados do navegador. Se o banco de dados resultante do navegador excede 64 MB, ou se o número de arquivos de entrada (. SBR) excede 4092, esse erro será emitido.

Se o problema é causado por arquivos de mais de 4092. SBR, você deve reduzir o número de arquivos de entrada. De dentro do Visual Studio, isso pode ser feito [/FR](../../build/reference/fr-fr-create-dot-sbr-file.md) seu projeto inteiro, em seguida, verificar novamente em uma base de arquivo por arquivo.

Se o problema é causado por um arquivo. bsc maior que 64MB, reduzindo o número de arquivos. SBR como entrada diminuirá o tamanho do arquivo. bsc resultante. Além disso, a quantidade de informações de pesquisa pode ser reduzida com o uso de /Em (Excluir Macro expandida símbolos), /El (excluir variáveis locais) e /Es (excluir arquivos do sistema).

## <a name="see-also"></a>Consulte também

[Opções de BSCMAKE](../../build/reference/bscmake-options.md)