---
title: "-INTEGRITYCHECK (Exigir verificação de assinatura) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 9e738825-2c98-40cd-8ad2-5d0d9c14893e
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 7bf86676ecbc37e346f538d180612f21352fb48b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="integritycheck-require-signature-check"></a>/INTEGRITYCHECK (exigir verificação de assinatura)
Especifica que a assinatura digital da imagem binária deve ser verificada em tempo de carregamento.  
  
```  
/INTEGRITYCHECK[:NO]  
```  
  
## <a name="remarks"></a>Comentários  
 Por padrão, **/INTEGRITYCHECK** está desativado.  
  
 O **/INTEGRITYCHECK** opção conjuntos — no cabeçalho PE do arquivo executável ou arquivo DLL — um sinalizador para o Gerenciador de memória verificar se há uma assinatura digital para carregar a imagem do Windows. Essa opção deve ser definida para DLLs de 32 bits e 64 bits que implementem o código de modo kernel carregado por determinados recursos do Windows e são recomendados para todos os drivers de dispositivo no Windows Vista, [!INCLUDE[win7](../../build/includes/win7_md.md)], [!INCLUDE[win8](../../build/reference/includes/win8_md.md)], [!INCLUDE[winsvr08](../../build/reference/includes/winsvr08_md.md)], e [!INCLUDE[winserver8](../../build/reference/includes/winserver8_md.md)]. Versões do Windows anterior ao Windows Vista ignoram esse sinalizador. Para obter mais informações, consulte [arquivos forçado a integridade de assinatura de PE (executável portátil)](http://social.technet.microsoft.com/wiki/contents/articles/255.forced-integrity-signing-of-portable-executable-pe-files.aspx).  
  
### <a name="to-set-this-linker-option-in-visual-studio"></a>Para definir essa opção do vinculador no Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter mais informações, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Expanda o **propriedades de configuração** nó.  
  
3.  Expanda o **vinculador** nó.  
  
4.  Selecione o **linha de comando** página de propriedades.  
  
5.  Em **opções adicionais**, digite `/INTEGRITYCHECK` ou `/INTEGRITYCHECK:NO`.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)   
 [Arquivos de integridade de assinatura de PE (executável portátil) forçado](http://social.technet.microsoft.com/wiki/contents/articles/255.forced-integrity-signing-of-portable-executable-pe-files.aspx)   
 [Instruções passo a passo de assinatura de código de modo kernel](http://msdn.microsoft.com/windows/hardware/gg487328.aspx)   
 [DLLs de AppInit no Windows 7 e Windows Server 2008](http://msdn.microsoft.com/windows/hardware/gg463040.aspx)