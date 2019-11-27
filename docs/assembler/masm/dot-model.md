---
title: .MODEL
ms.date: 11/05/2019
f1_keywords:
- .MODEL
helpviewer_keywords:
- .MODEL directive
ms.assetid: 057f00df-1515-4c55-852a-d936c8a34b53
ms.openlocfilehash: bfc114a6e71c0eb0ae70005c2657871b6c9e9692
ms.sourcegitcommit: 9ee5df398bfd30a42739632de3e165874cb675c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/22/2019
ms.locfileid: "74398105"
---
# <a name="model-32-bit-masm"></a>. MODELO (MASM de 32 bits)

Inicializa o modelo de memória do programa. (somente MASM de 32 bits.)

## <a name="syntax"></a>Sintaxe

> **. Modelo** *de memória-modelo* ⟦ __,__ *tipo de linguagem*⟧ ⟦ __,__ *Stack-Option*⟧

### <a name="parameters"></a>Parâmetros

\ *de modelo de memória*
Parâmetro obrigatório que determina o tamanho dos pontos de dados e código.

\ *de tipo de idioma*
Parâmetro opcional que define as convenções de nomenclatura e chamadas para procedimentos e símbolos públicos.

\ *de opção de pilha*
Parâmetro opcional.

*a opção de pilha* não será usada se o *modelo de memória* for **simples**.

Especificar **NEARSTACK** agrupa o segmento de pilha em um único segmento físico (**DGROUP**) junto com os dados. O registro de segmento de pilha (**SS**) é considerado para manter o mesmo endereço que o registro de segmento de dados (**DS**). **FARSTACK** não agrupa a pilha com **DGROUP**; Portanto, **SS** não é igual a **DS**.

## <a name="remarks"></a>Comentários

**. O modelo** não é usado em [MASM para x64 (ml64. exe)](../../assembler/masm/masm-for-x64-ml64-exe.md).

A tabela a seguir lista os possíveis valores para cada parâmetro ao direcionar plataformas de 16 bits e 32 bits:

|Parâmetro|Valores de 32 bits|Valores de 16 bits (suporte para o desenvolvimento de 16 bits anterior)|
|---------------|--------------------|----------------------------------------------------------------|
|*memória-modelo*|**PLANOS**|**minúsculo**, **pequeno**, **compacto**, **médio**, **grande**, **enorme**, **simples**|
|*tipo de idioma*|**C**, **stdcall**|**C**, **básico**, **Fortran**, **Pascal**, **syscall**, **stdcall**|
|*opção de pilha*|Não usado|**NEARSTACK**, **FARSTACK**|

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

[Referência de diretivas](../../assembler/masm/directives-reference.md)
