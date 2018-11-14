---
title: .MODEL
ms.date: 08/30/2018
f1_keywords:
- .MODEL
helpviewer_keywords:
- .MODEL directive
ms.assetid: 057f00df-1515-4c55-852a-d936c8a34b53
ms.openlocfilehash: e72101d2d9cdea90b3304ccdb82e7b81fe2975d3
ms.sourcegitcommit: 1819bd2ff79fba7ec172504b9a34455c70c73f10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2018
ms.locfileid: "51328526"
---
# <a name="model"></a>.MODEL

Inicializa o modelo de memória de programa.

## <a name="syntax"></a>Sintaxe

> . MODELO memorymodel [[, langtype]] [[, stackoption]]

### <a name="parameters"></a>Parâmetros

*memorymodel*<br/>
Parâmetro obrigatório que determina o tamanho dos ponteiros de código e os dados.

*langtype*<br/>
Parâmetro opcional que define as convenções de nomenclatura e chamadas de procedimentos e os símbolos públicos.

*stackoption*<br/>
Parâmetro opcional.

*stackoption* não será usado se *memorymodel* é `FLAT`.

Especificando `NEARSTACK` agrupa o segmento de pilha em um único segmento físico (`DGROUP`) junto com dados. O registro de segmento de pilha (`SS`) é assumido para manter o mesmo endereço que o registro do segmento de dados (`DS`). `FARSTACK` não agrupa a pilha com `DGROUP`; portanto `SS` não é igual a `DS`.

## <a name="remarks"></a>Comentários

.`MODEL` não é usado na [MASM para x64 (ml64.exe)](../../assembler/masm/masm-for-x64-ml64-exe.md).

A tabela a seguir lista os possíveis valores para cada parâmetro ao direcionar para plataformas de 16 bits e 32 bits:

|Parâmetro|valores de 32 bits|valores de 16 bits (suporte para desenvolvimento de 16 bits anterior)|
|---------------|--------------------|----------------------------------------------------------------|
|*memorymodel*|`FLAT`|`TINY`, `SMALL`, `COMPACT`, `MEDIUM`, `LARGE`, `HUGE`, `FLAT`|
|*langtype*|`C`, `STDCALL`|`C`, `BASIC`, `FORTRAN`, `PASCAL`, `SYSCALL`, `STDCALL`|
|*stackoption*|Não usado|`NEARSTACK`, `FARSTACK`|

## <a name="code"></a>Código

Para obter exemplos relacionados (MASM), baixe os exemplos de compilador do [exemplos do Visual C++ e a documentação relacionada para Visual Studio 2010](http://go.microsoft.com/fwlink/p/?linkid=178749).

O exemplo a seguir demonstra o uso da `.MODEL` diretiva.

## <a name="example"></a>Exemplo

```asm
; file simple.asm
; For x86 (32-bit), assemble with debug information:
;   ml -c -Zi simple.asm
; For x64 (64-bit), assemble with debug information:
;   ml64 -c -DX64 -Zi simple.asm
;
; In this sample, the 'X64' define excludes source not used
;  when targeting the x64 architecture

ifndef X64
.686p
.XMM
.model flat, C
endif

.data
; user data

.code
; user code

fxn PROC public
  xor eax, eax ; zero function return value
  ret
fxn ENDP

end
```

## <a name="see-also"></a>Consulte também

[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>

