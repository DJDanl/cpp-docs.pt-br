---
title: Pragma section
ms.date: 08/29/2019
f1_keywords:
- section_CPP
- vc-pragma.section
helpviewer_keywords:
- pragmas, section
- section pragma
ms.assetid: c67215e9-2c4a-4b0f-b691-2414d2e2d96f
ms.openlocfilehash: 47ae2ff2503317e937e2b3a497357afbd5522a64
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70216606"
---
# <a name="section-pragma"></a>Pragma section

Cria uma seção em um arquivo .obj.

## <a name="syntax"></a>Sintaxe

> **#pragma seção (** "*nome da seção*" [ **,** *atributos* ] **)**

## <a name="remarks"></a>Comentários

Os termos *segmento* e *seção* têm o mesmo significado neste artigo.

Quando uma seção é definida, ela permanece válida pelo restante da compilação. No entanto, você deve usar [_ declspec (allocate)](../cpp/allocate.md)ou nada é colocado na seção.

*Section-Name* é um parâmetro necessário que se torna o nome da seção. O nome não deve estar em conflito com os nomes de seção padrão. Consulte [/Section](../build/reference/section-specify-section-attributes.md) para obter uma lista de nomes que você não deve usar ao criar uma seção.

*atributos* é um parâmetro opcional que consiste em um ou mais atributos separados por vírgulas para atribuir à seção. Os *atributos* possíveis são:

|Atributo|Descrição|
|-|-|
|**read**|Permite operações de leitura em dados.|
|**write**|Permite operações de gravação em dados.|
|**execute**|Permite que o código seja executado.|
|**shared**|Compartilha a seção entre todos os processos que carregam a imagem.|
|**nopage**|Marca a seção como não paginável. Útil para drivers de dispositivo Win32.|
|**nocache**|Marca a seção como não armazenável em cache. Útil para drivers de dispositivo Win32.|
|**discard**|Marca a seção como descartada. Útil para drivers de dispositivo Win32.|
|**remove**|Marca a seção como não residente na memória. Somente para drivers de dispositivo virtual (V*x*D).|

Se você não especificar nenhum atributo, a seção terá atributos de **leitura** e **gravação** .

## <a name="example"></a>Exemplo

Neste exemplo, a primeira seção pragma identifica a seção e seus atributos. O inteiro `j` não é colocado em `mysec` porque não foi declarado usando `__declspec(allocate)`. Em vez `j` disso, entra na seção de dados. O inteiro `i` entra em `mysec` como resultado do atributo de classe de armazenamento `__declspec(allocate)`.

```cpp
// pragma_section.cpp
#pragma section("mysec",read,write)
int j = 0;

__declspec(allocate("mysec"))
int i = 0;

int main(){}
```

## <a name="see-also"></a>Consulte também

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
