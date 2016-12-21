---
title: "Pr&#225;ticas recomendadas de otimiza&#231;&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Visual C++, otimização"
  - "otimização, práticas recomendadas"
ms.assetid: f3433148-7255-4ca6-8a4f-7c31aac88508
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Pr&#225;ticas recomendadas de otimiza&#231;&#227;o
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este documento descreve algumas práticas recomendadas para a otimização no Visual C\+\+.  Os tópicos são discutidos:  
  
-   Opções do compilador e do vinculador  
  
    -   Otimização Perfil\- orientada  
  
    -   No nível de otimização que eu deveria usar?  
  
    -   Opções de ponto flutuante  
  
-   Otimização Declspecs  
  
-   Pragmas de otimização  
  
-   \_\_restrict e \_\_assume  
  
-   Suporte intrínseco  
  
-   Exceções  
  
## Opções do compilador e do vinculador  
  
### Otimização Perfil\- orientada  
 O oferece suporte do Visual C\+\+ perfil\- guiaram a otimização \(PGO\).  Essa otimização usa dados de perfil das últimas execuções de uma versão instrumentada de um aplicativo realizar uma otimização posterior do aplicativo.  Usar PGO pode ser demorada, portanto não pode ser algo que cada desenvolvedor usa, mas recomendamos usar PGO para a construção da versão final de um produto.  Para obter mais informações, consulte [Otimizações orientadas a perfil](../../build/reference/profile-guided-optimizations.md).  
  
 Além disso, a otimização de programa inteira \(também aprenderá a geração de código de tempo de link\) e as otimizações de **\/O1** e de **\/O2** foram aprimoradas.  Em geral, um aplicativo compilado com uma dessas opções será mais rápido do que o mesmo aplicativo compilado com um compilador anterior.  
  
 Para obter mais informações, consulte [\/GL \(otimização de todo o programa\)](../../build/reference/gl-whole-program-optimization.md) e [\/O1, \/O2 \(minimizar tamanho, maximizar velocidade\)](../../build/reference/o1-o2-minimize-size-maximize-speed.md).  
  
### No nível de otimização que eu deveria usar?  
 Se em qualquer possível, as construções da versão final são criadas com otimizações guiadas perfil.  Se não for possível criar com PGO, devido à falta de infraestrutura para a execução as construções ou o acesso provido não ter a cenários, então a nós sugerem compile com otimização de programa inteira.  
  
 A opção de **\/Gy** também é muito útil.  Gerencie um COMDAT separado para cada função, dando ao vinculador mais flexibilidade quando se trata de remover a dobra não referenciada de COMDATs e de COMDAT.  O único downside a usar **\/Gy** é que pode ter um efeito secundário no momento da compilação.  Consequentemente, geralmente é recomendável usá\-lo.  Para obter mais informações, consulte [\/Gy \(habilitar vinculação do nível de função\)](../../build/reference/gy-enable-function-level-linking.md).  
  
 Para vincular em ambientes de 64 bits, é recomendável usar a opção do vinculador de **\/OPT:REF,ICF** , e em ambientes de 32 bits, **\/OPT:REF** é recomendado.  Para obter mais informações, consulte [\/OPT \(Otimizações\)](../../build/reference/opt-optimizations.md).  
  
 Também é altamente recomendável gerar símbolos de depuração, mesmo com construções otimizadas de versão.  Não executar o código gerado, e facilita depurar seu aplicativo, se necessário.  
  
### Opções de ponto flutuante  
 A opção do compilador de **\/Op** foi removida, e seguinte tratar de quatro opções do compilador otimizações de ponto flutuante foi adicionado:  
  
|||  
|-|-|  
|**\/fp:precise**|Esta é a recomendação padrão e deve ser usada na maioria dos casos.|  
|**\/fp:fast**|Recomendado se o desempenho for predominante, por exemplo nos conjuntos.  Isso resulta em desempenho mais rápido.|  
|**\/fp:strict**|Recomendado se as exceções e o comportamento de ponto flutuante IEEE precisos são desejados.  Isso resulta em desempenho mais lento.|  
|**\/fp:except\[\-\]**|Pode ser usado junto com **\/fp:strict** ou **\/fp:precise**, mas não **\/fp:fast**.|  
  
 Para obter mais informações, consulte [\/fp \(especificar comportamento de ponto flutuante\)](../../build/reference/fp-specify-floating-point-behavior.md).  
  
## Otimização Declspecs  
 Nesta seção nós examinaremos dois declspecs que podem ser usados em programas para ajudar o desempenho: `__declspec(restrict)` e `__declspec(noalias)`.  
  
 O declspec de `restrict` só pode ser aplicado às declarações de funções que retornam um ponteiro, como `__declspec(restrict) void *malloc(size_t size);`  
  
 O declspec de `restrict` é usado em funções que retornam unaliased ponteiros.  Essa palavra\-chave é usado para a implementação da biblioteca de C \- tempo de execução de `malloc` desde que nunca retornarão um valor do ponteiro que já está em uso no programa atual \(a menos que você esteja fazendo algo ilegal, como a utilização da memória depois que for liberada\).  
  
 O declspec de `restrict` fornece ao compilador mais informações para executar otimizações de compilador.  Uma das coisas mais duras para que um compilador determinar o que é o alias dos ponteiros outros ponteiros, e o uso dessas informações ajudam muito o compilador.  
  
 Vale indicando que essa é uma promessa ao compilador, não algo que o compilador verificará.  Se seu programa usa esse declspec de `restrict` de forma inadequada, o programa pode ter comportamento incorreto.  
  
 Para obter mais informações, consulte [restrict](../../cpp/restrict.md).  
  
 O declspec de `noalias` também é aplicado somente a funções, e indica que a função é uma função e pura.  Uma função e pura é aquela que faz referência ou altera somente locais, argumentos, ações e indiretas de primeiro nível de argumentos.  Este declspec é uma promessa ao compilador, e se os globais de função ou as ações indiretas de segundo nível de argumentos do ponteiro no compilador podem gerar código interrompendo o aplicativo.  
  
 Para obter mais informações, consulte [noalias](../../cpp/noalias.md).  
  
## Pragmas de otimização  
 Também há vários pragmas úteis para ajudar otimiza o código.  Primeiro que nós discutiremos é `#pragma optimize`:  
  
```  
#pragma optimize("{opt-list}", on | off)  
```  
  
 Este pragma permite definir uma otimização determinada em nível em uma base de função\-por\- função.  Isso é ideal para essas raras ocasiões em que seu aplicativo falhar quando uma determinada função é criada com otimização.  Você pode usar isso para desativar otimizações para uma única função:  
  
```  
#pragma optimize("", off)  
int myFunc() {...}  
#pragma optimize("", on)  
```  
  
 Para obter mais informações, consulte [optimize](../../preprocessor/optimize.md).  
  
 Inlining é uma das otimizações as mais importantes que o compilador executa e aqui nós falamos sobre um par pragmas que ajudam a alterar esse comportamento.  
  
 `#pragma inline_recursion` é útil para especificar se você deseja que o aplicativo possa a embutido uma chamada recursiva.  Por padrão é.  Para a recursão superficial de funções pequenas você pode ativar esse em.  Para obter mais informações, consulte [inline\_recursion](../../preprocessor/inline-recursion.md).  
  
 Outro pragma útil para limitar a profundidade de inlining é `#pragma inline_depth`.  Isso normalmente é útil em situações em que você está tentando limitar o tamanho de um programa ou de uma função.  Para obter mais informações, consulte [inline\_depth](../../preprocessor/inline-depth.md).  
  
## \_\_restrict e \_\_assume  
 Há algumas palavras\-chave no Visual C\+\+ que pode ajudar no desempenho: [\_\_restrict](../../cpp/extension-restrict.md) e [\_\_assume](../../intrinsics/assume.md).  
  
 Primeiro, deve\-se observar que `__restrict` e `__declspec(restrict)` são duas coisas diferentes.  Quando elas estão relacionadas um pouco, a semântica é diferente.  `__restrict` é um qualificador de tipo, como `const` ou `volatile`, mas exclusivamente para tipos do ponteiro.  
  
 Um ponteiro que foi modificado com `__restrict` é conhecido como *um ponteiro de \_\_restrict*.  Um ponteiro de \_\_restrict é um ponteiro que pode ser acessado somente pelo ponteiro de \_\_restrict.  Ou é outro ponteiro não pode ser usado para acessar os dados apontados pelo ponteiro de \_\_restrict.  
  
 `__restrict` pode ser uma ferramenta ideal para o otimizador do Visual C\+\+, mas usá\-los com grande cuidado.  Se usado de forma incorreta, o otimizador pode executar uma otimização que interrompesse seu aplicativo.  
  
 A palavra\-chave de `__restrict` substitui a opção de **\/Oa** de versões anteriores.  
  
 Com `__assume,` um desenvolvedor pode informar o compilador para fazer suposições sobre o valor de qualquer variável.  
  
 Por exemplo `__assume(a < 5);` instrui o otimizador que nessa linha de código `a` variável for menor que 5.  Novamente essa é uma promessa ao compilador.  Se `a` é de fato 6 neste momento no programa em que o comportamento do programa depois que o compilador otimizado não pode ser o que você espera que.  `__assume` é muito útil antes que as instruções de opção e\/ou expressões condicionais.  
  
 Há algumas limitações a `__assume`.  Primeiro, como `__restrict`, é somente uma sugestão, assim que o compilador estiver livre ignore\-a.  Além disso, `__assume` atualmente funciona apenas com desigualdades variáveis em constantes.  Não se propaga de token desigualdades, por exemplo, suponha que um \( \< b\).  
  
## Suporte intrínseco  
 Os Intrinsics são as chamadas de função no compilador tem conhecimento sobre intrínseco a chamada, e em vez de chamar uma função em uma biblioteca, emite o código para essa função.  O arquivo de cabeçalho intrin.h localizado em \<Installation\_Directory\>\\VC\\include\\intrin.h contém todos os intrinsics disponíveis para cada uma das três plataformas com suporte \(x86, x64, e ARM\).  
  
 Os Intrinsics dão ao programador a capacidade de fazer logon no nível de profundidade de código sem ter que usar o assembly.  Há vários benefícios para usar intrinsics:  
  
1.  O código é mais portátil.  Vários intrinsics estão disponíveis em diversas arquiteturas de CPU.  
  
2.  O código é mais fácil de ler, desde que o código é gravado em ainda C\/C\+\+.  
  
3.  Seu código obtém o benefício de otimizações de compilador.  Como o compilador obtém melhor, a geração de código para os intrinsics melhora.  
  
 Para obter mais informações, consulte [Intrínsecos do compilador](../../intrinsics/compiler-intrinsics.md) e [Benefits of Using Intrinsics](http://msdn.microsoft.com/pt-br/57af8920-527f-44af-a741-a07cbe80bf02).  
  
## Exceções  
 Há um desempenho alcançado associado ao uso de exceções.  Algumas restrições são introduzidas ao usar os blocos da tentativa de inibem o compilador de executar certas otimizações.  Nas plataformas x86 há uma degradação de desempenho adicional dos blocos da tentativa devido às informações de estado adicional que deve ser gerada durante a execução do código.  Em plataformas de 64 bits, os bloqueios da tentativa não degradam o desempenho tanto quanto, mas depois que uma exceção é gerada, o processo de localizar e o manipulador de desenrolar a pilha pode ser dispendiosa.  
  
 Em virtude disso, é recomendável evitar enviar blocos try\/catch no código que o não precisa de fato.  Se você usar exceções, use exceções síncronas se possível.  Para obter mais informações, consulte [Tratamento de exceções estruturado](../../cpp/structured-exception-handling-c-cpp.md).  
  
 Finalmente, exceções de lançamento para casos excepcionais somente.  Usar exceções para o fluxo de controle geral provavelmente fará o desempenho ser afetado.  
  
## Consulte também  
 [Otimizando o código](../../build/reference/optimizing-your-code.md)