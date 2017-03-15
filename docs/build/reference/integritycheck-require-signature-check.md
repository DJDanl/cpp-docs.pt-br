---
title: "/INTEGRITYCHECK (exigir verifica&#231;&#227;o de assinatura) | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
ms.assetid: 9e738825-2c98-40cd-8ad2-5d0d9c14893e
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /INTEGRITYCHECK (exigir verifica&#231;&#227;o de assinatura)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Especifica que a assinatura digital da imagem binária deve ser marcada em tempo de carga.  
  
```  
/INTEGRITYCHECK[:NO]  
```  
  
## Comentários  
 Por padrão, **\/INTEGRITYCHECK** está desativado.  
  
 A opção **\/INTEGRITYCHECK** define, no cabeçalho PE ou no arquivo DLL ou executável, um sinalizador para que um gerente de memória verifique uma assinatura digital para carregar a imagem no Windows.  Essa opção deve ser definida para dlls de 32 bits e de 64 bits que implementam o código do modo kernel carregado por determinados recursos do windows, e é recomendada para todos os drivers de dispositivo no Windows Vista, em [!INCLUDE[win7](../../build/includes/win7_md.md)], em [!INCLUDE[win8](../../build/includes/win8_md.md)], em [!INCLUDE[winsvr08](../../build/includes/winsvr08_md.md)]e, em [!INCLUDE[winserver8](../../build/includes/winserver8_md.md)].  As versões do Windows antes do Windows Vista ignoram este sinalizador.  Para obter mais informações, consulte [Assinatura de integridade forçada de arquivos portáteis executáveis \(PE\)](http://social.technet.microsoft.com/wiki/contents/articles/255.forced-integrity-signing-of-portable-executable-pe-files.aspx).  
  
### Para definir essa opção de vinculador no Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter mais informações, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Expanda o nó **Propriedades de Configuração**.  
  
3.  Expanda o nó **Vinculador**.  
  
4.  Selecione a página de propriedades **Linha de Comando** .  
  
5.  Em **Opções Adicionais**, digite `/INTEGRITYCHECK` ou `/INTEGRITYCHECK:NO`.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)   
 [Assinatura de integridade forçada de arquivos portáteis executáveis \(PE\)](http://social.technet.microsoft.com/wiki/contents/articles/255.forced-integrity-signing-of-portable-executable-pe-files.aspx)   
 [Explicação passo a passo de assinatura de código de modo kernel](http://msdn.microsoft.com/windows/hardware/gg487328.aspx)   
 [DLL de AppInit no Windows 7 e Windows Server 2008](http://msdn.microsoft.com/windows/hardware/gg463040.aspx)