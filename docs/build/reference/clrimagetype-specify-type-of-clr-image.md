---
title: -CLRIMAGETYPE (especificar tipo de imagem CLR) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /CLRIMAGETYPE
- VC.Project.VCLinkerTool.CLRImageType
dev_langs: C++
helpviewer_keywords:
- /CLRIMAGETYPE linker option
- -CLRIMAGETYPE linker option
ms.assetid: 04c60ee6-9dd7-4391-bc03-6926ad0fa116
caps.latest.revision: "14"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b7d8edd6c9e62456e54ac6228f25d7f923a6813c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="clrimagetype-specify-type-of-clr-image"></a>/CLRIMAGETYPE (especificar tipo de imagem CLR)
```  
/CLRIMAGETYPE:{IJW|PURE|SAFE|SAFE32BITPREFERRED}  
```  
  
## <a name="remarks"></a>Comentários  
 O vinculador aceita objetos nativo e também MSIL objetos que são compilados usando [/clr](../../build/reference/clr-common-language-runtime-compilation.md), /clr: pure, ou /CLR: safe. As opções do compilador **/clr:pure** e **/clr:safe** são preteridas no Visual Studio 2015. Quando são passados mistos objetos na mesma compilação, a capacidade de verificação do arquivo de saída resultante é, por padrão, igual ao menor nível de capacidade de verificação dos módulos de entrada. Por exemplo, se você passar um cofre e um módulo puro para o vinculador, o arquivo de saída será puro. Se você passar uma imagem nativa e uma imagem de modo misto (compilados usando **/clr**), a imagem resultante será uma imagem de modo misto.  
  
 Você pode usar /CLRIMAGETYPE para especificar um nível mais baixo de capacidade de verificação, se esse for o que você precisa.  
  
 No .NET 4.5, /CLRIMAGETYPE dá suporte a uma opção de SAFE32BITPREFERRED. Isso define — no cabeçalho PE da imagem — sinalizadores que indicam que os objetos MSIL são seguros e podem ser executado em todas as plataformas, mas que os ambientes de execução de 32 bits são preferenciais. Essa opção permite que um aplicativo para ser executado em plataformas ARM e também especifica que ele deve ser executado no WOW64 em sistemas operacionais de 64 bits em vez de usar o ambiente de execução de 64 bits.  
  
 Quando um .exe que foi compilado usando **/clr** ou **/clr: pure** é executado em um sistema operacional de 64 bits, o aplicativo é executado no WOW64, que permite que um aplicativo de 32 bits executar em um sistema operacional de 64 bits. Por padrão, um que é compilado usando .exe **/CLR: safe** é executado com suporte de 64 bits do sistema operacional. No entanto, é possível que seu aplicativo seguro carrega um componente de 32 bits. Nesse caso, uma imagem de segurança em execução com suporte de 64 bits do sistema operacional falhará quando ele carrega o aplicativo de 32 bits. Para garantir que uma imagem de segurança continuará a ser executado quando ele carrega um componente de 32 bits em um sistema operacional de 64 bits, use a opção /CLRIMAGETYPE:SAFE32BITPREFERRED. Se seu código não precisa ser executado em plataformas ARM, você pode especificar o /CLRIMAGETYPE: PURE opção para alterar os metadados (.corflags), marcá-lo para ser executado no WOW64 (e substituir seu próprio símbolo de entrada):  
  
 **Cl /CLR: safe t.cpp /link /clrimagetype: pure /entry:?main@@$$HYMHXZ /Subsystem**  
  
 Para obter informações sobre como determinar o tipo de imagem CLR de um arquivo, consulte [/CLRHEADER](../../build/reference/clrheader.md).  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Expanda o **propriedades de configuração** nó.  
  
3.  Expanda o **vinculador** nó.  
  
4.  Selecione o **avançado** página de propriedades.  
  
5.  Modificar o **tipo de imagem CLR** propriedade.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.CLRImageType%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)