---
title: "-vmm, - vms, - /vmv (representação de finalidade geral) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /vms
- /vmm
- /vmv
dev_langs: C++
helpviewer_keywords:
- Virtual Inheritance compiler option
- general purpose representation compiler options
- vms compiler option [C++]
- vmm compiler option [C++]
- /vmm compiler option [C++]
- -vmm compiler option [C++]
- -vms compiler option [C++]
- /vms compiler option [C++]
- vmv compiler option [C++]
- /vmv compiler option [C++]
- Single Inheritance compiler option
- -vmv compiler option [C++]
ms.assetid: 0fcd7ae0-3031-4c62-a2a8-e154c8685dae
caps.latest.revision: "12"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 1de5d46375a48b3d0a97ee76486a11e8a6e71b6e
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="vmm-vms-vmv-general-purpose-representation"></a>/vmm, /vms, /vmv (representação de finalidade geral)
Usado quando [/vmb, /vmg (método de representação)](../../build/reference/vmb-vmg-representation-method.md) é selecionado como o [método de representação](../../build/reference/vmb-vmg-representation-method.md). Essas opções indicarem o modelo de herança da definição de classe ainda não encontrado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/vmm  
/vms  
/vmv  
```  
  
## <a name="remarks"></a>Comentários  
 As opções são descritas na tabela a seguir.  
  
|Opção|Descrição|  
|------------|-----------------|  
|**/VMM**|Especifica a representação mais geral de um ponteiro para um membro de uma classe para que usa várias heranças.<br /><br /> O correspondente [palavra-chave de herança](../../cpp/inheritance-keywords.md) e argumento [#pragma pointers_to_members](../../preprocessor/pointers-to-members.md) é **multiple_inheritance**.<br /><br /> Essa representação é maior do que o necessário para herança única.<br /><br /> Se o modelo de herança de uma definição de classe para o qual um ponteiro para um membro é declarado é virtual, o compilador gerará um erro.|  
|**/VMs**|Especifica a representação mais geral de um ponteiro para um membro de uma classe para que não usa herança única ou nenhuma herança.<br /><br /> O correspondente [palavra-chave de herança](../../cpp/inheritance-keywords.md) e argumento [#pragma pointers_to_members](../../preprocessor/pointers-to-members.md) é **single_inheritance**.<br /><br /> Esta é a menor representação possíveis de um ponteiro para um membro de uma classe.<br /><br /> Se o modelo de herança de uma definição de classe para o qual um ponteiro para um membro é declarado for múltipla ou virtual, o compilador gerará um erro.|  
|**/vmv**|Especifica a representação mais geral de um ponteiro para um membro de uma classe para que usa herança virtual. Ele nunca faz com que um erro e é o padrão.<br /><br /> O correspondente [palavra-chave de herança](../../cpp/inheritance-keywords.md) e argumento [#pragma pointers_to_members](../../preprocessor/pointers-to-members.md) é **virtual_inheritance**.<br /><br /> Essa opção requer um ponteiro maior e o código adicional para interpretar o ponteiro que as outras opções.|  
  
 Quando você especificar uma dessas opções de modelo de herança, esse modelo é usado para todos os ponteiros para membros de classe, independentemente de seu tipo de herança ou se o ponteiro é declarado antes ou depois da classe. Portanto, se você sempre pode usar classes de herança simples, você pode reduzir o tamanho de código ao compilar com **/vms**; no entanto, se você quiser usar o caso mais geral (às custas de maior representação de dados), compile com **/vmv**.  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Clique o **C/C++** pasta.  
  
3.  Clique o **linha de comando** página de propriedades.  
  
4.  Digite a opção de compilador no **opções adicionais** caixa.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [/vmb, /vmg (método de representação)](../../build/reference/vmb-vmg-representation-method.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)