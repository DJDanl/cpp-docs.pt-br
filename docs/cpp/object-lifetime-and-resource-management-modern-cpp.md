---
title: Objeto de tempo de vida e gerenciamento de recursos (C++ moderno) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-language
ms.tgt_pltfrm: ''
ms.topic: article
dev_langs:
- C++
ms.assetid: 8aa0e1a1-e04d-46b1-acca-1d548490700f
caps.latest.revision: 18
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4e2b48630fab9d27bf5db442617a5184bd26de5d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="object-lifetime-and-resource-management-modern-c"></a>Vida útil do objeto e gerenciamento de recursos (C++ moderno)
Ao contrário de linguagens gerenciadas, C++ não tem a coleta de lixo (GC), que libera automaticamente os recursos de memória não-mais-usado como um programa é executado. Em C++, o gerenciamento de recursos está diretamente relacionado ao tempo de vida do objeto. Este documento descreve os fatores que afetam a vida útil do objeto em C++ e como gerenciá-lo.  
  
 C++ não tem GC principalmente porque ele não dá suporte a recursos de memória não. Somente destruidores determinísticas como aqueles em C++ podem lidar com os recursos de memória e a memória não igualmente. GC também possui outros problemas, como maior sobrecarga na memória e o consumo de CPU e a localidade. Mas universality é um problema fundamental que não pode ser mitigado com otimizações inteligentes.  
  
## <a name="concepts"></a>Conceitos  
 Um importante no gerenciamento de vida útil do objeto é o encapsulamento — quem está usando um objeto não precisa saber o que possui recursos que o objeto, ou como eliminá-los ou até mesmo se ele possui todos os recursos em todos os. Ele tem apenas destruir o objeto. A linguagem do C++ core foi desenvolvida para garantir que os objetos são destruídos no horário correto, ou seja, como blocos são finalizados, em ordem inversa de construção. Quando um objeto é destruído, suas bases e membros são destruídos em uma ordem específica.  O idioma destrói automaticamente objetos, a menos que você fazer coisas especiais como alocação de heap ou a colocação de novo.  Por exemplo, [ponteiros inteligentes](../cpp/smart-pointers-modern-cpp.md) como `unique_ptr` e `shared_ptr`, e como contêineres da biblioteca padrão C++ `vector`, encapsular `new` / `delete` e `new[]` / `delete[]` em objetos, que possuem destrutores. É por isso que é tão importante usar ponteiros inteligentes e contêineres da biblioteca padrão C++.  
  
 Outro conceito importante no gerenciamento de vida útil: destruidores. Destruidores encapsulam a versão do recurso.  (O mnemônico usado é RRID, o recurso de versão é destruição.)  Um recurso é algo que você obtém do "sistema" e deve fornecer novamente mais tarde.  Memória é o recurso mais comuns, mas também há arquivos, soquetes, texturas e outros recursos sem memória. "Possui" um recurso significa que você pode usá-lo quando necessário, mas você também precisará liberá-lo quando tiver terminado com ele.  Quando um objeto é destruído, seu destruidor libera os recursos que ele pertence.  
  
 O conceito de final é o DAG (gráfico acíclico direcionado).  A estrutura de propriedade em um programa de forma um DAG. Nenhum objeto pode ser proprietário dele mesmo — que não é apenas impossível, mas também inerentemente sem sentido. Mas dois objetos podem compartilhar a propriedade de um objeto de terceiro.  Vários tipos de links são possíveis em um DAG como este: A é um membro de B (B possui um), C armazena um `vector<D>` (C possui cada elemento de D), E armazena um `shared_ptr<F>` (E compartilhamentos de propriedade de F, possivelmente com outros objetos), e assim por diante.  Contanto que não há nenhum ciclo e todos os links no DAG é representado por um objeto que tenha um destruidor (em vez de um ponteiro bruto, identificadores ou outro mecanismo), vazamentos de recursos serão impossíveis porque o idioma impede que eles. Recursos são liberados imediatamente depois que eles não são mais necessários, sem um coletor de lixo em execução. O controle de tempo de vida é livre de sobrecarga para o escopo de pilha, base, membros e os casos relacionados e baixo custo para `shared_ptr`.  
  
### <a name="heap-based-lifetime"></a>Tempo de vida de heap  
 Tempo de vida de objeto do heap, use [ponteiros inteligentes](../cpp/smart-pointers-modern-cpp.md). Use `shared_ptr` e `make_shared` como o ponteiro padrão e o alocador. Use `weak_ptr` para quebrar ciclos, faça o cache e observe objetos sem afetar ou supondo que nada sobre suas vidas úteis.  
  
```cpp  
void func() {  
  
auto p = make_shared<widget>(); // no leak, and exception safe  
...  
p->draw();   
  
} // no delete required, out-of-scope triggers smart pointer destructor  
  
```  
  
 Use `unique_ptr` proprie exclusivo, por exemplo, o *pimpl* idioma. (Consulte [Pimpl para encapsulamento do tempo de compilação](../cpp/pimpl-for-compile-time-encapsulation-modern-cpp.md).) Fazer um `unique_ptr` o destino principal de explícitos `new` expressões.  
  
```cpp  
unique_ptr<widget> p(new widget());  
```  
  
 Você pode usar ponteiros brutos de propriedade não e Observação. Um ponteiro não proprietário pode dangle, mas não pode perder.  
  
```cpp  
class node {  
  ...  
  vector<unique_ptr<node>> children; // node owns children  
  node* parent; // node observes parent, which is not a concern  
  ...  
};  
node::node() : parent(...) { children.emplace_back(new node(...) ); }  
  
```  
  
 Quando a otimização de desempenho é necessária, talvez você precise usar *bem encapsulada* possui ponteiros e chamadas explícitas a excluir. Um exemplo é quando você implementar sua própria estrutura de dados de nível baixo.  
  
### <a name="stack-based-lifetime"></a>Tempo de vida de pilha  
 No C++ moderna, *escopo baseado em pilha* é uma maneira eficiente para escrever um código robusto porque ele combina automático *tempo de vida de pilha* e *tempo de vida de membro de dados* com alta eficiência — controle de tempo de vida é essencialmente gratuito de sobrecarga. Vida útil do objeto heap requer o gerenciamento manual cuidadoso e pode ser a origem de vazamentos de recursos e as ineficiências, especialmente quando você estiver trabalhando com indicadores brutos. Considere este código, que demonstra o escopo de pilha:  
  
```cpp  
class widget {  
private:  
    gadget g;   // lifetime automatically tied to enclosing object  
public:  
    void draw();  
};  
  
void functionUsingWidget () {  
    widget w;   // lifetime automatically tied to enclosing scope  
                // constructs w, including the w.g gadget member  
    // ...
    w.draw();  
    // ...
} // automatic destruction and deallocation for w and w.g  
  // automatic exception safety,   
  // as if "finally { w.dispose(); w.g.dispose(); }"  
```  
  
 Use o tempo de vida estático com moderação (estático global, estática de local de função) porque podem ocorrer problemas. O que acontece quando o construtor de um objeto global gera uma exceção? Normalmente, as falhas de aplicativo de forma que pode ser difícil de depurar. Ordem de construção é problemático para objetos de tempo de vida estático e não é seguro de simultaneidade. Não só é a construção de objeto um problema, ordem de destruição pode ser complexo, especialmente onde polimorfismo está envolvido. Mesmo que seu objeto ou uma variável não é polimórfico e não tem ordenação construção/destruição complexa, há ainda o problema de simultaneidade do thread-safe. Um aplicativo multithread com segurança não é possível modificar os dados em objetos estáticos sem a necessidade de armazenamento local de thread, bloqueios de recursos e outras precauções especiais.  
  
## <a name="see-also"></a>Consulte também  
 [Bem-vindo novamente para C++](../cpp/welcome-back-to-cpp-modern-cpp.md)   
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)   
 [Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)