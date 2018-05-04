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
ms.openlocfilehash: 91f91373eef29adcb9a632e80520ed6713d3e39b
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="favor-optimize-for-architecture-specifics"></a>/favor (Otimizar para especificações da arquitetura)
**/favor:** `option` gera o código que é otimizado para uma arquitetura específica ou para as especificações de arquiteturas de micro o AMD e as arquiteturas Intel.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/favor:{blend | ATOM | AMD64 | INTEL64}  
```  
  
## <a name="remarks"></a>Comentários  
 **/favor:Blend**  
 (x86 e x64) gera o código que é otimizado para as especificações de arquiteturas de micro o AMD e as arquiteturas Intel. Enquanto **/favor:blend** pode não fornecer o melhor desempenho possível em um processador específico, ele é projetado para fornecer o melhor desempenho em uma ampla variedade de processadores x86 e x64. Por padrão, **/favor:blend** está em vigor.  
  
 **/favor:Atom**  
 (x86 e x64) gera o código que é otimizado para as especificações do processador Intel Atom e tecnologia de processador Intel Centrino Atom. Código que é gerado usando **/favor:ATOM** podem produzir SSSE3 Intel e SSE, SSE2 e SSE3 instruções para os processadores Intel.  
  
 **/favor:AMD64**  
 (x64) otimiza o código gerado para o AMD Opteron e processadores Athlon que dão suporte a extensões de 64 bits. O código otimizado pode executar em x64 todas as plataformas compatíveis. Código que é gerado usando **/favor:AMD64** pode causar a pior desempenho em processadores Intel que suportam Intel64.  
  
 **/favor:INTEL64**  
 (x64) otimiza o código gerado para os processadores Intel que suportam Intel64, que normalmente gera um desempenho melhor para a plataforma. O código resultante pode ser executado em qualquer x64 plataforma. Código que é gerado com **/favor:INTEL64** pode causar a pior desempenho em AMD Opteron e processadores Athlon que dão suporte a extensões de 64 bits.  
  
> [!NOTE]
>  Arquitetura de Intel64 era conhecida anteriormente como tecnologia Extended Memory 64, e a opção de compilador correspondente foi **/favor:EM64T**.  
  
 Para obter informações sobre como programar para o [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)] arquitetura, consulte [x64 convenções de Software](../../build/x64-software-conventions.md).  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **C/C++** pasta.  
  
3.  Selecione o **linha de comando** página de propriedades.  
  
4.  Insira a opção de compilador no **opções adicionais** caixa.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)