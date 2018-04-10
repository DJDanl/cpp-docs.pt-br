---
title: -Qfast_transcendentals (forçar transcendentais rápidos) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
ms.topic: article
f1_keywords:
- /Qfast_transcendentals
dev_langs:
- C++
helpviewer_keywords:
- /Qfast_transcendentals
- Force Fast Transcendentals
ms.assetid: 4de24bd1-38e6-49d4-9a05-04c9937d24ac
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f8d7e8de17c096d061653b469207352be4b9b8bf
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="qfasttranscendentals-force-fast-transcendentals"></a>/Qfast_transcendentals (forçar transcendentais rápidos)
Gera o código embutido para funções transcendentais.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Qfast_transcendentals  
```  
  
## <a name="remarks"></a>Comentários  
 Essa opção de compilador força transcendentais funções a ser convertido em código embutido para melhorar a velocidade de execução. Essa opção tem um efeito somente quando combinados com **/fp: exceto** ou **/fp: preciso**. Gerar código embutido para funções transcendentais já é o comportamento padrão em **Fast**.  
  
 Essa opção é incompatível com **/fp: strict**. Consulte [/fp (Especificar comportamento de ponto flutuante)](../../build/reference/fp-specify-floating-point-behavior.md) para obter mais informações sobre opções do compilador de ponto de flutuante.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **linha de comando** página de propriedades.  
  
4.  Digite a opção de compilador no **opções adicionais** caixa.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [/Q opções (operações de nível baixo)](../../build/reference/q-options-low-level-operations.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)