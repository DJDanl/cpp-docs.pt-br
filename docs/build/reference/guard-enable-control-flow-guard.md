---
title: "-prote&#231;&#227;o (Habilitar prote&#231;&#227;o de fluxo de controle) | Microsoft Docs"
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
  - "/guard"
  - "VC.Project.VCCLCompilerTool.ControlFlowGuard"
dev_langs: 
  - "C++"
ms.assetid: be495323-f59f-4cf3-a6b6-8ee69e6a19dd
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /guard (habilitar prote&#231;&#227;o do fluxo de controle)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Habilite a geração de compilador protetor de fluxo de controle de verificações de segurança.  
  
## Sintaxe  
  
```  
/guard:cf[-]  
```  
  
## Comentários  
 O **\/guard:cf** opção faz com que o compilador analisar o fluxo de controle para destinos de chamada indireta em tempo de compilação e, em seguida, insira o código para verificar se os destinos no tempo de execução. Por padrão, **\/guard:cf** está desativado e deve ser explicitamente habilitado. Para desabilitar explicitamente essa opção, use **\/guard:cf\-**.  
  
 Quando o **\/guard:cf** opção proteger o fluxo de controle \(CFG\) for especificada, o compilador e vinculador inserem verificações de segurança adicionais em tempo de execução para detectar tentativas de comprometer seu código. Durante a compilação e vinculação, todas as chamadas indiretas em seu código são analisadas para localizar todos os locais em que o código pode acessar quando ele é executado corretamente. Essas informações são armazenadas em estruturas adicionais nos cabeçalhos de seus binários. O compilador também injeta uma seleção antes de cada chamada indireta em seu código que garante que o destino é um dos locais verificados. Se a verificação falhar em tempo de execução em um sistema operacional CFG ciente, o sistema operacional fecha o programa.  
  
 Um ataque comum em software tira proveito dos bugs na manipulação de entradas extremas ou inesperadas. Entrada criada cuidadosamente para o aplicativo pode substituir um local que contém um ponteiro para o código executável. Isso pode ser usado para redirecionar o fluxo de controle para código controlado pelo invasor. As verificações de tempo de execução CFG não corrigir os bugs de corrupção de dados em seu executável. Eles em vez disso, tornam mais difícil para um invasor usá\-los para executar código arbitrário. CFG é uma ferramenta de atenuação que evita que as chamadas para locais diferentes pontos de entrada de função em seu código. É semelhante a como prevenção de execução de dados \(DEP\),  [\/GS](../Topic/-GS%20\(Buffer%20Security%20Check\).md) verificações de pilha e [\/DYNAMICBASE](../../build/reference/dynamicbase-use-address-space-layout-randomization.md) e [\/HIGHENTROPYVA](../Topic/-HIGHENTROPYVA%20\(Support%2064-Bit%20ASLR\).md) randomização de layout de espaço de endereço \(ASLR\) reduzir as chances de que seu código se torna um vetor de exploração.  
  
 O **\/guard:cf** opção deve ser passada para ambas as o compilador e vinculador para compilar o código que usa o CFG explorar técnica de atenuação. Se o binário é criado usando um único `cl` de comando, o compilador passa a opção para o vinculador. Se você compilar e vincular separadamente, a opção deve ser definida no compilador e vinculador comandos. A opção de vinculador \/DYNAMICBASE também é necessária. Para verificar se seu binário tem dados de configuração, use o `dumpbin /headers /loadconfig` comando. Tem ativado CFG binários `Guard` na lista de características do EXE ou DLL e sinalizadores de proteção incluem `CF instrumentado` e `tabela FID presentes`.  
  
 O **\/guard:cf** opção é incompatível com [\/ZI](../Topic/-Z7,%20-Zi,%20-ZI%20\(Debug%20Information%20Format\).md) \(Editar e continuar informações de depuração\) ou [\/clr](../../build/reference/clr-common-language-runtime-compilation.md) \(Common Language Runtime Compilation\).  
  
 Código compilado usando **\/guard:cf** podem ser vinculados a bibliotecas e arquivos que não são compilados usando a opção do objeto. Apenas este código, quando vinculado também usando o **\/guard:cf** opção e executado em um sistema operacional com reconhecimento de CFG, com proteção CFG. Como o código compilado sem a opção não irá parar um ataque, é recomendável que você usa a opção em todo o código que você compila. Há um runtime pequeno custo para verificações de configuração, mas a análise de compilador tenta otimizar as verificações em saltos indiretas que podem ser comprovados por segurança.  
  
### Para definir essa opção de compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra o projeto **páginas de propriedade** caixa de diálogo. Para obter detalhes, consulte [Como abrir páginas de propriedade do projeto](../../misc/how-to-open-project-property-pages.md).  
  
2.  Selecione **Propriedades de configuração**, **C\/C\+\+**, **geração de código**.  
  
3.  Selecione o **protetor de fluxo de controle** propriedade.  
  
4.  No controle de lista suspensa, escolha **Sim** para habilitar o protetor de fluxo de controle, ou **não** para desabilitá\-lo.  
  
## Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../Topic/Setting%20Compiler%20Options.md)