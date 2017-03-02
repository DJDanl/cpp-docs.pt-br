---
title: Erro fatal C1092 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1092
dev_langs:
- C++
helpviewer_keywords:
- C1092
ms.assetid: bcaa87f0-fbfc-4a33-844b-3b9f5d67f279
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 6cad5222fb0d97594d5b13b5cf8903eb2934ee88
ms.openlocfilehash: 6d93fd662b638126e21d5f5f034138c0e6f0e0ad
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1092"></a>Erro fatal C1092
Editar e Continuar não suporta alterações em tipos de dados; compilação necessária  
  
 Você alterados ou adicionados a um tipo de dados desde a última compilação bem-sucedida.  
  
-   Editar e continuar não dá suporte a alterações de tipos de dados existentes, inclusive definições de classe, struct ou enum. Você deve parar a depuração e compilar o aplicativo.  
  
-   Editar e continuar não dá suporte a adição de novos tipos de dados se um arquivo de banco de dados do programa, como o vc*x*0. pdb (onde *x* é a versão principal do Visual C++ em uso) é somente leitura. Para adicionar tipos de dados, o compilador deve abrir o arquivo. PDB no modo de gravação.  
  
### <a name="to-remove-this-error-without-ending-the-current-debug-session"></a>Para remover este erro sem encerrar a sessão de depuração atual  
  
1.  Altere o tipo de dados a seu estado antes do erro.  
  
2.  Do **depurar** menu, escolha **aplicar alterações de código**.  
  
### <a name="to-remove-this-error-without-changing-your-source-code"></a>Para remover este erro sem alterar o código-fonte  
  
1.  Do **depurar** menu, escolha **parar depuração**.  
  
2.  Do **criar** menu, escolha **criar**.  
  
 Para obter mais informações, consulte o [Supported Code Changes](/visualstudio/debugger/supported-code-changes-cpp).
