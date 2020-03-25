---
title: Erro BK1503 (BSCMAKE)
ms.date: 11/04/2016
f1_keywords:
- BK1503
helpviewer_keywords:
- BK1503
ms.assetid: e6582344-b91e-486f-baf3-4f9028d83c3b
ms.openlocfilehash: e0f05b3979024cb053394c51fa9337197b5de7bf
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80197854"
---
# <a name="bscmake-error-bk1503"></a>Erro BK1503 (BSCMAKE)

Não é possível gravar no arquivo ' FileName ' [: reason]

BSCMAKE combina os arquivos. sbr gerados durante a compilação em um banco de dados do navegador. Se o banco de dados do navegador resultante exceder 64 MB ou se o número de arquivos de entrada (. sbr) exceder 4092, esse erro será emitido.

Se o problema for causado por mais de 4092 arquivos. SBR, você deverá reduzir o número de arquivos de entrada. No Visual Studio, isso pode ser feito por meio do [/fr](../../build/reference/fr-fr-create-dot-sbr-file.md) de todo o seu projeto e, em seguida, verificar novamente um arquivo por arquivo.

Se o problema for causado por um arquivo. BSC maior que 64MB, reduzir o número de arquivos. sbr como entrada diminuirá o tamanho do arquivo. BSC resultante. Além disso, a quantidade de informações de procura pode ser reduzida com o uso do/em (excluir símbolos expandidos de macro),/El (excluir variáveis locais) e/es (excluir arquivos do sistema).

## <a name="see-also"></a>Confira também

[Opções de BSCMAKE](../../build/reference/bscmake-options.md)
