---
title: __lzcnt16, __lzcnt, __lzcnt64
ms.date: 11/04/2016
f1_keywords:
- __lzcnt64
- __lzcnt16
- __lzcnt
helpviewer_keywords:
- __lzcnt intrinsic
- lzcnt instruction
- lzcnt16 intrinsic
- lzcnt intrinsic
- __lzcnt16 intrinsic
- lzcnt64 intrinsic
- __lzcnt64 intrinsic
ms.assetid: 412113e7-052e-46e5-8bfa-d5ad72abc10e
ms.openlocfilehash: 6e7685e13faa82a03640701539454ddc8729c94f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50461393"
---
# <a name="lzcnt16-lzcnt-lzcnt64"></a>__lzcnt16, __lzcnt, __lzcnt64

**Seção específica da Microsoft**

Contagens de que o número de líderes zeros em um 16, 32 ou inteiro de 64 bits.

## <a name="syntax"></a>Sintaxe

```
unsigned short __lzcnt16(
   unsigned short value
);
unsigned int __lzcnt(
   unsigned int value
);
unsigned __int64 __lzcnt64(
   unsigned __int64 value
);
```

#### <a name="parameters"></a>Parâmetros

*value*<br/>
[in] 16-, 32 ou 64 bits de inteiro sem sinal de verificação de zeros à esquerda.

## <a name="return-value"></a>Valor de retorno

O número de bits zero à esquerda o `value` parâmetro. Se `value` for zero, o valor de retorno é o tamanho do operando entrado (16, 32 ou 64). Se a maioria dos bit significativo de `value` é um, o valor retornado será zero.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__lzcnt16`|AMD: Manipulação de Bit avançado (ABM)<br /><br /> Intel: Haswell|
|`__lzcnt`|AMD: Manipulação de Bit avançado (ABM)<br /><br /> Intel: Haswell|
|`__lzcnt64`|AMD: Avançadas de manipulação de Bit (ABM) no modo de 64 bits.<br /><br /> Intel: Haswell|

**Arquivo de cabeçalho** \<intrin. h >

## <a name="remarks"></a>Comentários

Cada um desses intrínsecos gera o `lzcnt` instrução.  O tamanho do valor que o `lzcnt` instrução retorna é o mesmo que o tamanho do seu argumento.  No modo de 32 bits não há nenhum 64-bit registros de uso geral, portanto, não de 64 bits `lzcnt`.

Para determinar o suporte de hardware para o `lzcnt` chamada de instrução de `__cpuid` intrínseco com `InfoType=0x80000001` e verifique se o bit 5 da `CPUInfo[2] (ECX)`. Esse bit será 1 se a instrução for compatível e 0 caso contrário. Se você executar o código que usa esse intrínseco no hardware que não oferece suporte a `lzcnt` instrução, os resultados serão imprevisíveis.

Em processadores Intel que não dão suporte a `lzcnt` instrução, a codificação de byte de instrução é executada como `bsr` (bit inverso de verificação). Se a portabilidade do código for uma preocupação, considere o uso do `_BitScanReverse` intrínseco em vez disso. Para obter mais informações, consulte [_BitScanReverse, _BitScanReverse64](../intrinsics/bitscanreverse-bitscanreverse64.md).

## <a name="example"></a>Exemplo

```
// Compile this test with: /EHsc
#include <iostream>
#include <intrin.h>
using namespace std;

int main()
{
  unsigned short us[3] = {0, 0xFF, 0xFFFF};
  unsigned short usr;
  unsigned int   ui[4] = {0, 0xFF, 0xFFFF, 0xFFFFFFFF};
  unsigned int   uir;

  for (int i=0; i<3; i++) {
    usr = __lzcnt16(us[i]);
    cout << "__lzcnt16(0x" << hex << us[i] << ") = " << dec << usr << endl;
  }

  for (int i=0; i<4; i++) {
    uir = __lzcnt(ui[i]);
    cout << "__lzcnt(0x" << hex << ui[i] << ") = " << dec << uir << endl;
  }
}

```

```Output
__lzcnt16(0x0) = 16
__lzcnt16(0xff) = 8
__lzcnt16(0xffff) = 0
__lzcnt(0x0) = 32
__lzcnt(0xff) = 24
__lzcnt(0xffff) = 16
__lzcnt(0xffffffff) = 0
```

**Fim da seção específica da Microsoft**

Partes deste conteúdo são Copyright 2007 Advanced Micro dispositivos, Inc. Todos os direitos reservados. Reproduzido com a permissão do Advanced Micro dispositivos, Inc.

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
