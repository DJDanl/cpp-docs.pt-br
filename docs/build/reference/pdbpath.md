---
title: /PDBPATH
ms.date: 11/04/2016
f1_keywords:
- /pdbpath
helpviewer_keywords:
- .pdb files, path
- -PDBPATH dumpbin option
- /PDBPATH dumpbin option
- PDBPATH dumpbin option
- PDB files, path
ms.assetid: ccf67dcd-0b23-4250-ad47-06c48acbe82b
ms.openlocfilehash: f29b8e61fbfbdb0f373e3e7510cb3f1fe0b9cc2a
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57809204"
---
# <a name="pdbpath"></a>/PDBPATH

```
/PDBPATH[:VERBOSE] filename
```

### <a name="parameters"></a>Parâmetros

*filename*<br/>
O nome do arquivo. dll ou .exe para o qual você deseja encontrar o arquivo. PDB correspondente.

**:VERBOSE**<br/>
(Opcional) Relata todos os diretórios em que foi feita uma tentativa para localizar o arquivo. PDB.

## <a name="remarks"></a>Comentários

/PDBPATH pesquisará seu computador ao longo dos caminhos mesmos que o depurador possa pesquisar por um arquivo. PDB e relatará que, se houver, arquivos. PDB correspondem ao arquivo especificado na *filename*.

Ao usar o depurador do Visual Studio, você pode enfrentar um problema devido ao fato de que o depurador está usando um arquivo. PDB para uma versão diferente do arquivo que você está depurando.

/PDBPATH irá procurar por arquivos. PDB ao longo dos caminhos a seguir:

- Verifique o local em que reside o executável.

- Verifique o local do PDB gravado no executável. Isso geralmente é o local no momento em que a imagem foi vinculada.

- Verificar ao longo do caminho de pesquisa configurado no IDE do Visual Studio.

- Verifique as variáveis de ambiente ao longo dos caminhos na _NT_ALT_SYMBOL_PATH e NT_SYMBOL_PATH.

- Verifique no diretório do Windows.

## <a name="see-also"></a>Consulte também

[Opções de DUMPBIN](dumpbin-options.md)<br/>
[/PDBALTPATH (usar caminho de PDB alternativo)](pdbaltpath-use-alternate-pdb-path.md)
