---
title: __lzcnt16, __lzcnt, __lzcnt64
ms.date: 09/02/2019
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
ms.openlocfilehash: fcd801717974a230fbd19cc7802d8f6a011774f7
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70221807"
---
# <a name="__lzcnt16-__lzcnt-__lzcnt64"></a>__lzcnt16, __lzcnt, __lzcnt64

**Seção específica da Microsoft**

Conta o número de zeros à esquerda em um inteiro de 16, 32-ou 64 bits.

## <a name="syntax"></a>Sintaxe

```C
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

### <a name="parameters"></a>Parâmetros

*value*\
no O inteiro sem sinal de 16, 32-ou 64 bits para verificar se há zeros à esquerda.

## <a name="return-value"></a>Valor retornado

O número de zero bits à esquerda no `value` parâmetro. Se `value` for zero, o valor de retorno será o tamanho do operando de entrada (16, 32 ou 64). Se o bit mais significativo de `value` for um, o valor de retorno será zero.

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__lzcnt16`|AMD Manipulação de bits avançada (ABM)<br /><br /> Processador Haswell|
|`__lzcnt`|AMD Manipulação de bits avançada (ABM)<br /><br /> Processador Haswell|
|`__lzcnt64`|AMD Manipulação de bits avançada (ABM) no modo de 64 bits.<br /><br /> Processador Haswell|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

Cada um dos intrínsecos gera a `lzcnt` instrução.  O tamanho do valor que a `lzcnt` instrução retorna é igual ao tamanho de seu argumento.  No modo de 32 bits, não há nenhum registro de finalidade geral de 64 bits, portanto, não há suporte `lzcnt` para o 64-bit.

Para determinar o suporte de hardware `lzcnt` para a instrução, `__cpuid` chame o `InfoType=0x80000001` intrínseco e verifique o bit `CPUInfo[2] (ECX)`5 de. Esse bit será 1 se a instrução tiver suporte e 0 caso contrário. Se você executar o código que usa o intrínseco em hardware que não oferece `lzcnt` suporte à instrução, os resultados serão imprevisíveis.

Em processadores Intel que não dão suporte `lzcnt` à instrução, a codificação de byte de instrução `bsr` é executada como (exame de bit reverso). Se a portabilidade do código for uma preocupação, considere o `_BitScanReverse` uso de intrínseco. Para obter mais informações, consulte [_BitScanReverse, _BitScanReverse64](../intrinsics/bitscanreverse-bitscanreverse64.md).

## <a name="example"></a>Exemplo

```cpp
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

Partes desse conteúdo são direitos autorais 2007 da Advanced Micro Devices, Inc. Todos os direitos reservados. Reproduzida com a permissão da Advanced Micro Devices, Inc.

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
