---
title: .MODEL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- .MODEL
dev_langs:
- C++
helpviewer_keywords:
- .MODEL directive
ms.assetid: 057f00df-1515-4c55-852a-d936c8a34b53
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2814b1b6cc4483807f77989ff4fbb70929400d6e
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
ms.locfileid: "32057741"
---
# <a name="model"></a>.MODEL
Inicializa o modelo de memória de programa.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
.MODEL memorymodel [[, langtype]] [[, stackoption]]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `memorymodel`  
 Parâmetro obrigatório que determina o tamanho dos ponteiros de código e os dados.  
  
 `langtype`  
 Parâmetro opcional que define as convenções de nomenclatura e chamadas para procedimentos e símbolos públicos.  
  
 `stackoption`  
 Parâmetro opcional.  
  
 `stackoption` não é usado se `memorymodel` é `FLAT`.  
  
 Especificando `NEARSTACK` agrupa o segmento de pilha em um único segmento físico (`DGROUP`) junto com dados. Registro do segmento de pilha (`SS`) é assumido para manter o mesmo endereço de registro do segmento de dados (`DS`). `FARSTACK` não agrupa a pilha com `DGROUP`; portanto, `SS` não é igual a `DS`.  
  
## <a name="remarks"></a>Comentários  
 .`MODEL` não é usado em [MASM para x64 (ml64.exe)](../../assembler/masm/masm-for-x64-ml64-exe.md).  
  
 A tabela a seguir lista os possíveis valores para cada parâmetro no direcionamento para plataformas de 16 bits e 32 bits:  
  
|Parâmetro|valores de 32 bits|valores de 16 bits (suporte para o desenvolvimento de 16 bits anterior)|  
|---------------|--------------------|----------------------------------------------------------------|  
|`memorymodel`|`FLAT`|`TINY`, `SMALL`, `COMPACT`, `MEDIUM`, `LARGE`, `HUGE`, `FLAT`|  
|`langtype`|`C`, `STDCALL`|`C`, `BASIC`, `FORTRAN`, `PASCAL`, `SYSCALL`, `STDCALL`|  
|`stackoption`|Não usado|`NEARSTACK`, `FARSTACK`|  
  
## <a name="code"></a>Código  
 Para obter exemplos relacionados MASM, baixe os exemplos de compilador do [amostras do Visual C++ e a documentação relacionada para Visual Studio 2010](http://go.microsoft.com/fwlink/p/?linkid=178749).  
  
 O exemplo a seguir demonstra o uso da `.MODEL` diretiva.  
  
## <a name="example"></a>Exemplo  
  
```  
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
 [Amostras do Visual C++ e a documentação relacionada para Visual Studio 2010](http://go.microsoft.com/fwlink/p/?linkid=178749)