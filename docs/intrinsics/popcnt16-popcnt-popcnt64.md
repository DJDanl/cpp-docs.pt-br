---
title: __popcnt16, __popcnt, __popcnt64
ms.date: 09/02/2019
f1_keywords:
- __popcnt64
- __popcnt
- __popcnt16
helpviewer_keywords:
- popcnt instruction
- __popcnt16
- __popcnt64
- __popcnt
ms.assetid: e525b236-adc8-42df-9b9b-8b7d8c245d3b
ms.openlocfilehash: 3e5ae7f897500775671f8bd2563028874579a627
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70221364"
---
# <a name="__popcnt16-__popcnt-__popcnt64"></a>__popcnt16, __popcnt, __popcnt64

**Seção específica da Microsoft**

Conta o número de `1` bits (contagem de população) em um inteiro de 16, 32-ou de 64 bits sem sinal.

## <a name="syntax"></a>Sintaxe

```C
unsigned short __popcnt16(
   unsigned short value
);
unsigned int __popcnt(
   unsigned int value
);
unsigned __int64 __popcnt64(
   unsigned __int64 value
);
```

### <a name="parameters"></a>Parâmetros

*value*\
no O inteiro sem sinal de 16, 32-ou 64 bits para o qual desejamos a contagem de população.

## <a name="return-value"></a>Valor retornado

O número de `1` bits no parâmetro de *valor* .

## <a name="requirements"></a>Requisitos

|Intrínseco|Arquitetura|
|---------------|------------------|
|`__popcnt16`|Manipulação de bits avançada|
|`__popcnt`|Manipulação de bits avançada|
|`__popcnt64`|Manipulação de bit avançada no modo de 64 bits.|

**Arquivo de cabeçalho** \<> intrin. h

## <a name="remarks"></a>Comentários

Cada um dos intrínsecos gera a `popcnt` instrução. No modo de 32 bits, não há nenhum registro de finalidade geral de 64 bits; portanto, não há `popcnt` suporte para 64 bits.

Para determinar o suporte de hardware `popcnt` para a instrução, `__cpuid` chame o `InfoType=0x00000001` intrínseco e verifique o bit `CPUInfo[2] (ECX)`23 de. Esse bit será 1 se a instrução tiver suporte e 0 caso contrário. Se você executar o código que usa esses intrínsecos em hardware que não oferece `popcnt` suporte à instrução, os resultados serão imprevisíveis.

## <a name="example"></a>Exemplo

```cpp
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
    usr = __popcnt16(us[i]);
    cout << "__popcnt16(0x" << hex << us[i] << ") = " << dec << usr << endl;
  }

  for (int i=0; i<4; i++) {
    uir = __popcnt(ui[i]);
    cout << "__popcnt(0x" << hex << ui[i] << ") = " << dec << uir << endl;
  }
}
```

```Output
__popcnt16(0x0) = 0
__popcnt16(0xff) = 8
__popcnt16(0xffff) = 16
__popcnt(0x0) = 0
__popcnt(0xff) = 8
__popcnt(0xffff) = 16
__popcnt(0xffffffff) = 32
```

**Fim da seção específica da Microsoft**

Partes de Copyright 2007 da Advanced Micro Devices, Inc. Todos os direitos reservados. Reproduzida com a permissão da Advanced Micro Devices, Inc.

## <a name="see-also"></a>Consulte também

[Intrínsecos do compilador](../intrinsics/compiler-intrinsics.md)
