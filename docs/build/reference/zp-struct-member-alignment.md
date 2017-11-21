---
title: -Zp (alinhamento de membro de Struct) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /zp
- VC.Project.VCCLCompilerTool.StructMemberAlignment
- VC.Project.VCCLWCECompilerTool.StructMemberAlignment
dev_langs: C++
helpviewer_keywords:
- Struct Member Alignment compiler option
- Zp compiler option
- /Zp compiler option [C++]
- -Zp compiler option [C++]
ms.assetid: 5242f656-ed9b-48a3-bc73-cfcf3ed2520f
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 0743c9c11af61356806eb0f42efb8bba8139479b
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="zp-struct-member-alignment"></a>/Zp (alinhamento de membro do Struct)
Controla como os membros de uma estrutura são incluídos em memória e especifica a remessa mesmo para todas as estruturas em um módulo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Zp[1|2|4|8|16]  
```  
  
## <a name="remarks"></a>Comentários  
 Quando você especificar essa opção, cada membro da estrutura após a primeira é armazenado no tamanho do tipo de membro ou `n`-limites de bytes (onde `n` é 1, 2, 4, 8 ou 16), o que for menor.  
  
 Os valores disponíveis são descritos na tabela a seguir.  
  
 1  
 Empacota estruturas em limites de 1 byte. Mesmo que **/Zp**.  
  
 2  
 Empacota estruturas em limites de 2 bytes.  
  
 4  
 Empacota estruturas em limites de 4 bytes.  
  
 8  
 Empacota estruturas em limites de 8 bytes (padrão).  
  
 16  
 Empacota estruturas em limites de 16 bytes.  
  
 Você não deve usar essa opção, a menos que você tem requisitos específicos de alinhamento.  
  
 Você também pode usar [pacote](../../preprocessor/pack.md) a remessa de estrutura de controle. Para obter mais informações sobre alinhamento, consulte:  
  
-   [align](../../cpp/align-cpp.md)  
  
-   [Operador __alignof](../../cpp/alignof-operator.md)  
  
-   [__unaligned](../../cpp/unaligned.md)  
  
-   [Exemplos de alinhamento da estrutura](../../build/examples-of-structure-alignment.md) (específico para x64)  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **geração de código** página de propriedades.  
  
4.  Modificar o **alinhamento de membro de Struct** propriedade.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.StructMemberAlignment%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)