---
title: seção | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- section_CPP
- vc-pragma.section
dev_langs:
- C++
helpviewer_keywords:
- pragmas, section
- section pragma
ms.assetid: c67215e9-2c4a-4b0f-b691-2414d2e2d96f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a8d113c10ea8370a46560ba8668546c74b19c6f8
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33849936"
---
# <a name="section"></a>section
Cria uma seção em um arquivo .obj.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
#pragma section( "section-name" [, attributes] )  
```  
  
## <a name="remarks"></a>Comentários  
 O significado dos termos de *segmento* e *seção* são intercambiáveis neste tópico.  
  
 Quando uma seção é definida, ela permanece válida pelo restante da compilação. No entanto, você deve usar [__declspec(allocate)](../cpp/allocate.md) ou nada será colocado na seção.  
  
 *nome da seção* é um parâmetro obrigatório que será o nome da seção. O nome não deve estar em conflito com os nomes de seção padrão. Consulte [/seção](../build/reference/section-specify-section-attributes.md) para obter uma lista de nomes que você não deve usar ao criar uma seção.  
  
 `attributes` é um parâmetro opcional que consiste em um ou mais atributos separados por vírgulas que você deseja atribuir à seção. Os `attributes` possíveis são:  
  
 **read**  
 Permite operações de leitura em dados.  
  
 **write**  
 Permite operações de gravação em dados.  
  
 **execute**  
 Permite que o código seja executado.  
  
 **shared**  
 Compartilha a seção entre todos os processos que carregam a imagem.  
  
 **nopage**  
 Marca a seção como não paginável; útil para drivers de dispositivo do Win32.  
  
 **nocache**  
 Marca a seção como não colocável em cache; útil para drivers de dispositivo do Win32.  
  
 **discard**  
 Marca a seção como descartável; útil para drivers de dispositivo do Win32.  
  
 **remove**  
 Marca a seção como não residentes na memória; drivers de dispositivo virtual (V*x*D) apenas.  
  
 Se você não especificar atributos, a seção terá os atributos de leitura e gravação.  
  
## <a name="example"></a>Exemplo  
 No exemplo a seguir, a primeira instrução identifica a seção e os seus atributos. O inteiro `j` não é colocado em `mysec` porque não foi declarado com `__declspec(allocate)`; `j` entra na seção de dados. O inteiro `i` entra em `mysec` como resultado do atributo de classe de armazenamento `__declspec(allocate)`.  
  
```  
// pragma_section.cpp  
#pragma section("mysec",read,write)  
int j = 0;  
  
__declspec(allocate("mysec"))  
int i = 0;  
  
int main(){}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)