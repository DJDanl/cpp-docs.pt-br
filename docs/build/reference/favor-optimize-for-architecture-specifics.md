---
title: -Favorecer (otimizar para especificações da arquitetura) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /favor
dev_langs:
- C++
helpviewer_keywords:
- -favor compiler option [C++]
- /favor compiler option [C++]
ms.assetid: ad264df2-e30f-4d68-8bd0-10d6bee71a2a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 75081c3a2e8918bfe8abf43373d755ca258f2595
ms.sourcegitcommit: a41c4d096afca1e9b619bbbce045b77135d32ae2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/14/2018
ms.locfileid: "42573118"
---
# <a name="favor-optimize-for-architecture-specifics"></a>/favor (Otimizar para especificações da arquitetura)
**/favor:** `option` produz o código que é otimizado para uma arquitetura específica ou para as especificações de microarquiteturas na AMD e as arquiteturas Intel.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/favor:{blend | ATOM | AMD64 | INTEL64}  
```  
  
## <a name="remarks"></a>Comentários  
 **/favor: Blend**  
 (x86 e x64) produzem o código que é otimizado para as especificações de microarquiteturas na AMD e as arquiteturas Intel. Embora **/favor: Blend** podem não oferecer o melhor desempenho possível em um processador específico, ele é projetado para fornecer o melhor desempenho em uma ampla gama de processadores x86 e x64. Por padrão, **/favor: Blend** está em vigor.  
  
 **/favor:Atom**  
 (x86 e x64) produzem o código que é otimizado para as especificações do processador Intel Atom e tecnologia de processador Intel Centrino Atom. Código que é gerado pelo uso **/favor:ATOM** também pode produzir SSSE3 Intel e SSE, SSE2 e SSE3 instruções para os processadores Intel.  
  
 **/favor:AMD64**  
 (somente x64) otimiza o código gerado para o AMD Opteron e processadores Athlon que dão suporte a extensões de 64 bits. O código otimizado pode executar em x64 todas as plataformas compatíveis. Código que é gerado pelo uso **/favor:AMD64** pode causar um desempenho pior em processadores Intel que suportam Intel64.  
  
 **/favor:INTEL64**  
 (somente x64) otimiza o código gerado para processadores Intel que suportam Intel64, que normalmente gera um melhor desempenho para a plataforma. O código resultante pode ser executado em qualquer x64 plataforma. Código que é gerado com **/favor:INTEL64** podem causar um desempenho pior no AMD Opteron e processadores Athlon que dão suporte a extensões de 64 bits.  
  
> [!NOTE]
>  Arquitetura de Intel64 era conhecida como Extended Memory 64 Technology e a opção de compilador correspondente foi **/favor:EM64T**.  
  
 Para obter informações sobre como programar para o x64 arquitetura, consulte [x64 convenções de Software](../../build/x64-software-conventions.md).  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **C/C++** pasta.  
  
3.  Selecione o **linha de comando** página de propriedades.  
  
4.  Insira a opção de compilador na **opções adicionais** caixa.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)