---
title: .MODEL
ms.date: 08/30/2018
f1_keywords:
- .MODEL
helpviewer_keywords:
- .MODEL directive
ms.assetid: 057f00df-1515-4c55-852a-d936c8a34b53
ms.openlocfilehash: c409bf10a2f863c380cda6b4822583ffb3787da6
ms.sourcegitcommit: 61121faf879cc581a4d39e4baccabf7cf1f673a5
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/20/2019
ms.locfileid: "65934094"
---
# <a name="model"></a>.MODEL

Inicializa o modelo de memória do programa.

## <a name="syntax"></a>Sintaxe

> .MODEL memorymodel [[, langtype]] [[, stackoption]]

### <a name="parameters"></a>Parâmetros

*memorymodel*<br/>
Parâmetro obrigatório que determina o tamanho dos pontos de dados e código.

*langtype*<br/>
Parâmetro opcional que define as convenções de nomenclatura e chamadas para procedimentos e símbolos públicos.

*stackoption*<br/>
Parâmetro opcional.

*stackoption* não será usado se *memorymodel* for `FLAT`.

Especificar `NEARSTACK` agrupa o segmento de pilha em um único segmento físico (`DGROUP`) junto com os dados. O registro do segmento de pilhas (`SS`) deve ter o mesmo endereço que o registro do segmento de dados (`DS`). O `FARSTACK` não agrupa a pilha com `DGROUP`, portanto, `SS` não é igual a `DS`.

## <a name="remarks"></a>Comentários

.`MODEL` não é usado em [MASM para x64 (ml64.exe)](../../assembler/masm/masm-for-x64-ml64-exe.md).

A tabela a seguir lista os possíveis valores para cada parâmetro ao direcionar plataformas de 16 bits e 32 bits:

|Parâmetro|Valores de 32 bits|Valores de 16 bits (suporte para o desenvolvimento de 16 bits anterior)|
|---------------|--------------------|----------------------------------------------------------------|
|*memorymodel*|`FLAT`|`TINY`, `SMALL`, `COMPACT`, `MEDIUM`, `LARGE`, `HUGE`, `FLAT`|
|*langtype*|`C`, `STDCALL`|`C`, `BASIC`, `FORTRAN`, `PASCAL`, `SYSCALL`, `STDCALL`|
|*stackoption*|Não usado|`NEARSTACK`, `FARSTACK`|

## <a name="code"></a>Código

Para obter amostras relacionadas a MASM, baixe as amostras de Compilador em [Amostras do Visual C++ e documentação relacionada para o Visual Studio 2010](https://go.microsoft.com/fwlink/p/?linkid=178749).

O exemplo a seguir demonstra o uso da diretiva `.MODEL`.

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
