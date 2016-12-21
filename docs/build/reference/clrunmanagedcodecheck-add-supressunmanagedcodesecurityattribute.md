---
title: "/CLRUNMANAGEDCODECHECK (Adicionar SupressUnmanagedCodeSecurityAttribute) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/CLRUNMANAGEDCODECHECK"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /CLRUNMANAGEDCODECHECK"
  - "opção de vinculador -CLRUNMANAGEDCODECHECK"
ms.assetid: 73abc426-dab0-45e2-be85-0f9a14206cc2
caps.latest.revision: 15
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /CLRUNMANAGEDCODECHECK (Adicionar SupressUnmanagedCodeSecurityAttribute)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

**\/CLRUNMANAGEDCODECHECK** especifica se o vinculador aplicará <xref:System.Security.SuppressUnmanagedCodeSecurityAttribute> para chamar vinculador\- gerados de `PInvoke` de código gerenciado na DLL nativos.  
  
## Sintaxe  
  
```  
/CLRUNMANAGEDCODECHECK[:NO]  
```  
  
## Comentários  
 Por padrão, o vinculador aplica o SuppressUnmanagedCodeSecurityAttribute para chamar vinculador\- gerados de `PInvoke` .  Quando **\/CLRUNMANAGEDCODECHECK** é aplicado, SuppressUnmanagedCodeSecurityAttribute não é aplicada.  
  
 O vinculador adiciona somente o atributo aos objetos criados com **\/clr** ou **\/clr:pure**.  O vinculador não gerencia chamadas de `PInvoke` nos objetos compilados com **\/clr:safe**.  Para obter mais informações, consulte [\/clr \(compilação do Common Language Runtime\)](../../build/reference/clr-common-language-runtime-compilation.md).  
  
 Uma chamada de `PInvoke` é gerado pelo vinculador quando o vinculador não pode localizar um símbolo gerenciado para satisfazer uma referência de um chamador gerenciado mas pode localizar um símbolo nativo para satisfazer essa referência.  Para obter mais informações sobre `PInvoke`, consulte [Chamando funções nativas a partir do código gerenciado](../../dotnet/calling-native-functions-from-managed-code.md).  
  
 Observe que se você usar <xref:System.Security.AllowPartiallyTrustedCallersAttribute> em seu código, você deve definir explicitamente **\/CLRUNMANAGEDCODECHECK**.  É vulnerabilidade de segurança potencial se uma imagem conterá os atributos de SuppressUnmanagedCodeSecurity e AllowPartiallyTrustedCallers.  
  
 Consulte [Security Optimizations](http://msdn.microsoft.com/pt-br/cf255069-d85d-4de3-914a-e4625215a7c0) para obter mais informações sobre as consequências de usar SuppressUnmanagedCodeSecurityAttribute.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Expanda o nó **Propriedades de Configuração**.  
  
3.  Expanda o nó **Vinculador**.  
  
4.  Selecione a página de propriedades **Avançadas**.  
  
5.  Modifique a propriedade de **Verificação do Código Não Gerenciado CLR** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
1.  Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.CLRUnmanagedCodeCheck%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)